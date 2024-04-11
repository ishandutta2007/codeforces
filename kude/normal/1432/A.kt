fun main() {
    var tt = readLine()!!.toInt()
    repeat(tt) {
        solve()
    }
}

fun solve(): Unit {
    val (a, b) = readLine()!!.split(" ").map{it.toInt()}.toIntArray()
    println(a + b)
}