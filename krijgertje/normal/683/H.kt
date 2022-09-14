
fun main(args: Array<String>) {
	val s1=readLine()!!.split(' ')
	val n=s1[0].toInt(); val k=s1[1].toLong()
	val p=readLine()!!.split(' ').map{s->s.toInt()-1}
	val ret=Array<Int>(n,{i->-1})
	val lst=Array<Int>(n,{i->-1})
	for(i in 0..n-1) if(ret[i]==-1) {
		var cnt=0; var at=i
		while(ret[at]==-1) { ret[at]=-2; lst[cnt++]=at; at=p[at] }
		val ck:Int=(k%cnt).toInt()
		for(j in 0..cnt-1) ret[lst[(j+ck)%cnt]]=lst[j]+1
	}
	for(i in 0..n-1) { if(i!=0) print(" "); print(ret[i]) }; println()
}