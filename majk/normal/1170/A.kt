fun main() {
    val Q = readLine()!!.toInt()
    repeat(Q) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        val z = Math.min(x,y) - 1
        println("${x-z} ${y-z} $z")
    }
}