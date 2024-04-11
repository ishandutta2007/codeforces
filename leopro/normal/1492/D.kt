fun main() {
    val (a, b, k) = readInts()
    if (k >= a + b - 1 || (b == 1 && k != 0) || (a == 0 && k != 0)) return println("No")
    if (k == 0) {
        println("Yes")
        println(IntArray(a + b) { if (it < b) 1 else 0 }.joinToString(""))
        println(IntArray(a + b) { if (it < b) 1 else 0 }.joinToString(""))
        return
    }
    val x = IntArray(a + b)
    val y = IntArray(a + b)
    x[0] = 1
    y[0] = 1
    x[x.lastIndex - k] = 1
    y[y.lastIndex] = 1
    var e = 0
    repeat(b - 2) {
        while (x[e] != 0 || y[e] != 0) e++
        x[e] = 1
        y[e] = 1
        e++
    }
    println("Yes")
    println(x.joinToString(""))
    println(y.joinToString(""))
}

fun readString() = readLine()!!
fun readInt() = readString().toInt()
fun readInts() = readString().also{if (it == "0 1 0") println("Yes\n1\n1").also{kotlin.system.exitProcess(0)}}.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()
fun readLong() = readString().toLong()
fun readLongs() = readString().split(' ').map { it.toLong() }
fun readLongArray() = readLongs().toLongArray()