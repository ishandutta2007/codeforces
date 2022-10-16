fun readInt() = readLine()!!.toInt() // single int

fun readStrings() = readLine()!!.split(" ") // list of strings

fun readInts() = readStrings().map { it.toInt() } // list of ints

fun min(a: Int, b: Int): Int {
    if(a < b)
        return a
    return b
}

fun main() {
    var t = readLine()!!.toInt()
    while (t > 0)
    {
        t--
       	val n = readInt()
       	val a = readInts()
       	val b = readInts()
       	val c = readInt()
       	println (min(b[1], a[1] + c - a[0]))
    }
}