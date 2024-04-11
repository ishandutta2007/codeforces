fun run() {
    val (n,len) = readLine()!!.split(" ").map{it.toInt()}
    val have = (0 until n).map{readLine()!!}.toSet()
    val q = readLine()!!.toInt()
    repeat(q) {
        val t = readLine()!!
        println((0..len).map{t.removeRange(it..it)}.distinct().filter{have.contains(it)}.count())
    }
}

fun main() {
    run()
}