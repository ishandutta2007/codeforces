fun readset():List<Int> = readLine()!!.split(' ').map(String::toInt).drop(1)

fun main(args: Array<String>) {
	val a=readset()
	val b=readset()
	val c=a.union(b).minus(a.intersect(b))
	print(c.size)
	for(x in c.sorted()) print(" $x")
	println()
}