
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val a = readInts().sorted()
    var total = 0
    for (i in 0 until n step 2) {
        total += a[i+1]-a[i]
    }
    println(total)
}