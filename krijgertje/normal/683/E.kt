fun main(args: Array<String>) {
	val n=readLine()!!.toInt()
	val a=readLine()!!.split(' ').map(String::toInt)
	val ret=mutableListOf<Int>()
	var i=n-1;
	while(i>=0) {
		ret.add(a[i],i+1)
		--i;
	}
	for(x in ret) {
		if(x!=ret[0]) print(" ")
		print(x)
	}
	println()
}