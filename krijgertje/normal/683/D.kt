fun ok(n:Int, m:Int, p:Int):Boolean {
	var a=1;
	while(a*a<=p) {
		if(p%a==0&&(a<=n&&p/a<=m||a<=m&&p/a<=n)) return true
		++a
	}
	return false
}

fun main(args: Array<String>) {
	val t=readLine()!!.toInt()
	for(i in 0..t-1) {
		val (n,m,p)=readLine()!!.split(' ').map(String::toInt)
		println(if (ok(n,m,p)) "Yes" else "No")
	}
}