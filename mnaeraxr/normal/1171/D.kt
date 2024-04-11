import java.lang.Integer.min
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (x, y, z) = readInts()
    var (a, b, c) = readInts()

    if (x > a) no()

    a -= x
    val ya = min(y, a)
    y -= ya
    a -= ya

    val yb = min(y, b)
    y -= yb
    b -= yb

    if (y > 0) no()

    if (a + b + c < z) no()

    println("YES")

}

fun no() {
    println("NO")
    exitProcess(0)
}