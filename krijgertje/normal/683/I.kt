fun findspecial(g: MutableList<String>):Array<Array<Int>> {
	var x=-1; var y=-1; var lx=-1; var ly=-1; var tx=-1; var ty=-1
	for(cx in 0..g.size-1) for(cy in 0..g[cx].length-1) {
		if(g[cx][cy]=='Y') { x=cx; y=cy; }
		if(g[cx][cy]=='B') { lx=cx; ly=cy; }
		if(g[cx][cy]=='T') { tx=cx; ty=cy; }
	}
	return arrayOf(arrayOf(x,y),arrayOf(lx,ly),arrayOf(tx,ty))
}
fun encode(x:Int, y:Int, lx:Int, ly:Int, h:Int, w:Int):Int = ((x*w+y)*h+lx)*w+ly
fun decode(at:Int, h:Int, w:Int):Array<Int> {
	var cat=at; val ly=cat%w; cat/=w; val lx=cat%h; cat/=h; val y=cat%w; cat/=w; val x=cat
	return arrayOf(x,y,lx,ly)
}
fun getchar(at:Int, to:Int, h:Int, w:Int):Char {
	val (x,y,lx,ly)=decode(at,h,w)
	val (nx,ny)=decode(to,h,w)
	if(x+1==nx) return if(lx==nx&&ly==ny) 'S' else 's'
	if(x-1==nx) return if(lx==nx&&ly==ny) 'N' else 'n'
	if(y+1==ny) return if(lx==nx&&ly==ny) 'E' else 'e'
	if(y-1==ny) return if(lx==nx&&ly==ny) 'W' else 'w'
	return '?'
}

fun main(args: Array<String>) {
	val (h,w)=readLine()!!.split(' ').map(String::toInt)
	val g=mutableListOf<String>()
	for(x in 0..h-1) g.add(readLine()!!)
	
	val DX=arrayOf(0,+1,0,-1); val DY=arrayOf(+1,0,-1,0)
	val a=Array<Int>(h*w*h*w,{i->-1})
	val b=Array<Int>(h*w*h*w,{i->-1})
	val prv=Array<Int>(h*w*h*w,{i->-1})
	val p=Array<Int>(h*w*h*w,{i->-1}); var phead=0; var ptail=0
	val q=Array<Int>(h*w*h*w,{i->-1}); var qhead=0; var qtail=0
	val (sxy,slxy,txy)=findspecial(g); val(sx,sy)=sxy; val(slx,sly)=slxy; val(tx,ty)=txy
	val init=encode(sx,sy,slx,sly,h,w)
	a[init]=0; b[init]=0; prv[init]=-2; q[qhead++]=init
	while(qtail<qhead||ptail<phead) {
		val qat=if(qtail<qhead) q[qtail] else -1
		val pat=if(ptail<phead) p[ptail] else -1
		val at=if(qat!=-1&&(pat==-1||b[qat]<b[pat]||b[qat]==b[pat]&&a[qat]<=a[pat])) q[qtail++] else p[ptail++]
		val (x,y,lx,ly)=decode(at,h,w)
		//println("($x,$y) [$lx,$ly] = ${b[at]} pushes and ${a[at]} total")
		if(lx==tx&&ly==ty) {
			println("YES")
			val sb=StringBuilder(); var cat=at;
			while(prv[cat]>=0) { sb.append(getchar(prv[cat],cat,h,w)); cat=prv[cat]; }
			println(sb.reverse())
			return;
		}
		for(k in 0..3) {
			val nx=x+DX[k]; val ny=y+DY[k]; var nlx=lx; var nly=ly; val na=a[at]+1; var nb=b[at]
			if(nx<0||nx>=h||ny<0||ny>=w||g[nx][ny]=='X') continue
			if(nx==lx&&ny==ly) { nlx+=DX[k]; nly+=DY[k]; ++nb; }
			if(nlx<0||nlx>=h||nly<0||nly>=w||g[nlx][nly]=='X') continue
			val to=encode(nx,ny,nlx,nly,h,w)
			if(prv[to]!=-1&&(b[to]<nb||b[to]==nb&&a[to]<=na)) continue
			a[to]=na; b[to]=nb; prv[to]=at; if(nb==b[at]) q[qhead++]=to; else p[phead++]=to;
		}
	}
	println("NO")
}