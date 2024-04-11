fun encode(x:Int, y:Int, w:Int):Int = x*w+y
fun decode(at:Int, w:Int):Array<Int> {
	var cat=at; val y=cat%w; cat/=w; val x=cat
	return arrayOf(x,y)
}
fun print(g:MutableList<String>, cx:Int, cy:Int) {
	for(x in 0..g.size-1) { for(y in 0..g[x].length-1) print(if(x==cx&&y==cy) 'E' else if(g[x][y]=='E') '.' else g[x][y]); println() }
}
fun print(d:Array<Array<Int>>) {
	for(x in 0..d.size-1) { for(y in 0..d[x].size-1) print(if(d[x][y]==-1) " X" else " ${d[x][y]}"); println() }
}
fun print(ordered:Array<Int>, w:Int) {
	for(i in 0..ordered.size-1) { val (x,y)=decode(ordered[i],w); print("($x,$y)") }; println()
}
fun findspecial(g: MutableList<String>):Array<Int> {
	var x=-1; var y=-1; var tx=-1; var ty=-1
	for(cx in 0..g.size-1) for(cy in 0..g[cx].length-1) {
		if(g[cx][cy]=='E') { x=cx; y=cy; }
		if(g[cx][cy]=='T') { tx=cx; ty=cy; }
	}
	return arrayOf(x,y,tx,ty)
}
fun findDist(g:MutableList<String>, h:Int, w:Int, sx:Int, sy:Int): Array<Array<Int>> {
	val DX=arrayOf(0,+1,0,-1); val DY=arrayOf(+1,0,-1,0)
	val d=Array<Array<Int>>(h,{x->Array<Int>(w,{y->-1})})
	val q=Array<Int>(h*w,{i->-1}); var qhead=0; var qtail=0
	d[sx][sy]=0; q[qhead++]=encode(sx,sy,w)
	while(qtail<qhead) {
		val at=q[qtail++]
		val (x,y)=decode(at,w)
		for(k in 0..3) {
			val nx=x+DX[k]; val ny=y+DY[k]
			if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='X'||d[nx][ny]!=-1&&d[nx][ny]<=d[x][y]+1) continue
			d[nx][ny]=d[x][y]+1; q[qhead++]=encode(nx,ny,w)			
		}
	}
	return d
}
fun findPrev(g:MutableList<String>, d:Array<Array<Int>>, h:Int, w:Int, x:Int, y:Int):Array<Int> {
	val DX=arrayOf(0,+1,0,-1); val DY=arrayOf(+1,0,-1,0)
	for(k in 0..3) {
		val nx=x+DX[k]; val ny=y+DY[k]
		if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='X'||d[nx][ny]!=d[x][y]-1) continue
		return arrayOf(nx,ny)
	}
	throw RuntimeException("No prev found")
}
fun findPath(g:MutableList<String>, d:Array<Array<Int>>, h:Int, w:Int, tx:Int, ty:Int):StringBuilder {
	val ret=StringBuilder()
	var cx=tx; var cy=ty
	while(d[cx][cy]!=0) {
		val (nx,ny)=findPrev(g,d,h,w,cx,cy)
		if(cx==nx+1) ret.append('S'); else if(cx==nx-1) ret.append('N'); else if(cy==ny+1) ret.append('E'); else if(cy==ny-1) ret.append('W'); else ret.append('?')
		cx=nx; cy=ny
	}
	return ret.reverse()
}
fun findShelter(g:MutableList<String>, h:Int, w:Int, sx:Int, sy:Int):Array<Int> {
	val DX=arrayOf(0,+1,0,-1); val DY=arrayOf(+1,0,-1,0)
	for(dx in -1..+1) for(dy in -1..+1) {
		val nx=sx+dx; val ny=sy+dy
		if(nx<0||nx>=h||ny<0||ny>=w) continue
		if(g[nx][ny]=='T') return arrayOf(-1,-1)
	}
	for(k1 in 0..3) for(k2 in 0..3) {
		val ax=sx+DX[k1]; val ay=sy+DY[k1]; val bx=ax+DX[k2]; val by=ay+DY[k2]
		if(ax<0||ax>=h||ay<0||ay>=w||g[ax][ay]=='X') continue
		if(bx<0||bx>=h||by<0||by>=w||g[bx][by]=='X') continue
		if(bx<=sx-2||bx>=sx+2||by<=sy-2||by>=sy+2) return arrayOf(bx,by)
	}
	for(k1 in 0..3) for(k2 in 0..3) for(k3 in 0..3) {
		val ax=sx+DX[k1]; val ay=sy+DY[k1]; val bx=ax+DX[k2]; val by=ay+DY[k2]; val cx=bx+DX[k3]; val cy=by+DY[k3]
		if(ax<0||ax>=h||ay<0||ay>=w||g[ax][ay]=='X') continue
		if(bx<0||bx>=h||by<0||by>=w||g[bx][by]=='X') continue
		if(cx<0||cx>=h||cy<0||cy>=w||g[cx][cy]=='X') continue
		if(cx<=sx-2||cx>=sx+2||cy<=sy-2||cy>=sy+2) return arrayOf(cx,cy)
	}
	return arrayOf(-1,-1)
}
class Pair(val cost:Int, val id:Int) : Comparable<Pair> {
	override operator fun compareTo(other: Pair):Int = this.cost-other.cost
}
fun findOrder(g:MutableList<String>, d:Array<Array<Int>>, h:Int, w:Int, sx:Int, sy:Int):Array<Int> {
	val e=Array<Array<Int> >(h,{x->Array<Int>(w,{y->-1})})
	val q=Array<Array<Int> >(9,{z->Array<Int>(h*w,{i->-1})}); var qhead=Array<Int>(9,{i->0}); var qtail=Array<Int>(9,{i->0})
	var cz=0; val init=encode(sx,sy,w); e[sx][sy]=cz; q[cz][qhead[cz]++]=init;
	while(true) {
		val pz=cz; while(cz<pz+9&&qtail[cz%9]>=qhead[cz%9]) cz++; if(qtail[cz%9]==qhead[cz%9]) break;
		val at=q[cz%9][qtail[cz%9]++]; val (x,y)=decode(at,w)
		if(e[x][y]!=cz) continue
		for(dx in -1..+1) for(dy in -1..+1) {
			if(dx==0&&dy==0) continue
			val nx=x+dx; val ny=y+dy
			if(nx<0||nx>=h||ny<0||ny>=w) continue
			val nz=cz+(if((dx==0||dy==0)&&g[nx][ny]!='X') 1 else if(dx==0||dy==0) 7 else 8)
			if(e[nx][ny]!=-1&&e[nx][ny]<=nz) continue
			val to=encode(nx,ny,w); e[nx][ny]=nz; q[nz%9][qhead[nz%9]++]=to
		}
	}
	val pairs = mutableListOf<Pair>()
	for(x in 0..h-1) for(y in 0..w-1) if(d[x][y]!=-1) {
		var any=false; var exit=false; var mn=-1
		for(dx in -1..+1) for(dy in -1..+1) {
			val nx=x+dx; val ny=y+dy
			if(nx<0||nx>=h||ny<0||ny>=w) continue
			if(g[nx][ny]=='X') { any=true; if(mn==-1||e[nx][ny]<mn) mn=e[nx][ny] }
			if(g[nx][ny]=='T') exit=true
		}
		if(mn==-1) continue
		if(any&&!exit) pairs.add(Pair(d[x][y]+mn,encode(x,y,w)))
	}
	val ret=Array<Int>(pairs.size,{i->-1}); var nret=0
	for(pair in pairs.sorted()) ret[nret++]=pair.id
	return ret
}
	
fun main(args: Array<String>) {
	val (h,w)=readLine()!!.split(' ').map(String::toInt)
	val g=mutableListOf<String>()
	for(x in 0..h-1) g.add(readLine()!!)
	
	val ret=StringBuilder()
	var (x,y,tx,ty)=findspecial(g)
	while(true) {
		//println(); println(ret); print(g,x,y)
		var d=findDist(g,h,w,x,y)
		//print(d)
		if(d[tx][ty]!=-1) {
			ret.append(findPath(g,d,h,w,tx,ty));
			println(ret)
			return
		}
		val ordered=findOrder(g,d,h,w,tx,ty)
		//print(ordered,w)
		var found=false
		for(i in 0..ordered.size-1) {
			val (bx,by)=decode(ordered[i],w)
			if(d[bx][by]==-1) continue
			val (wx,wy)=findShelter(g,h,w,bx,by)
			if(wx==-1||wy==-1) continue
			//println("bomb ($bx,$by) shelter ($wx,$wy)")
			ret.append(findPath(g,d,h,w,bx,by)); x=bx; y=by
			ret.append('M'); val olen=ret.length;
			d=findDist(g,h,w,x,y)
			ret.append(findPath(g,d,h,w,wx,wy)); x=wx; y=wy
			while(ret.length<olen+3) ret.append('T');
			for(dx in -1..+1) for(dy in -1..+1) {
				val nx=bx+dx; val ny=by+dy
				if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]!='X') continue
				g[nx]=g[nx].substring(0..ny-1)+'-'+g[nx].substring(ny+1)
			}
			found=true; break
		}
		if(!found) break
	}
	println("No solution")
}