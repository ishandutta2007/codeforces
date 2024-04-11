
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (a, x, y) = readInts()
    
    if(x < 0 || x > a || y < 0 || y > a) {
        println(2)
    }else if(x == 0 || x == a || y == 0 || y == a) {
        println(1)
    }else {
        println(0)
    }
}