
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    repeat(t) {
        val (n,k) = readInts()
        var word = CharArray(n) { 'a' + it%k }
        println(word)
    }
}