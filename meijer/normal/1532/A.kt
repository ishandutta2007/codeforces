
fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    while(t != 0) {
        val (a,b) = readInts()
        println(a+b)
        t--
    }
}