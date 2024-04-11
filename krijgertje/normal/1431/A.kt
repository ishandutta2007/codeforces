fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }


fun run() {
    val (n) = readInts()
    val a = readLongs().toLongArray()
    a.sort()
    var ret: Long = 0
    for(i in 0 until n) ret=maxOf(ret,(n-i)*a[i])
    println(ret)
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}