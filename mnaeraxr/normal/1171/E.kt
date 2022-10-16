import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var n = readInt()

    if (n == 1) {
        println("Yes")
        exitProcess(0)
    }

    val s = readLn()

    val ss = s.toCharArray()
    ss.sort()

    while (n > 1) {
        if (ss[n - 1] == ss[n - 2]){
            println("Yes")
            exitProcess(0)
        }
        n -= 1
    }

    println("No")
}