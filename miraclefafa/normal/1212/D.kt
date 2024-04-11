import kotlin.Comparable

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

data class number(val va : Long, val p2 : Int, var p3 : Int) : Comparable<number>{
    override fun compareTo(other:number) = when {
		p2 != other.p2 -> p2 - other.p2
		else -> other.p3 - p3
	}
}

fun main() {
    var n=readInt()
    var a=readLongs().toMutableList()
    var c=ArrayList<number>()
    for (i in 0..n-1) {
        var x=a[i]
        var p2=0
        var p3=0
        while (x%2==0L) {
            x/=2
            p2+=1
        }
        while (x%3==0L) {
            x/=3
            p3+=1
        }
        c.add(number(a[i],p2,p3))
    }
    c.sort()
    println(c.map{it.va}.joinToString(" "))
}