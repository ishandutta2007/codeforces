private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()

    while (t > 0) {
        val a = readInt()

        val x = (a + 6) / 7

        println(x)

        t -= 1
    }
}