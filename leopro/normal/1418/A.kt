fun main() {
    for (i in 0 until readInts().first()) {
        val (x, y, k) = readLongs()
        val cube = k * y
        println((k + cube + x - 3) / (x - 1) + k)
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readLongs() = readLine()!!.split(' ').map { it.toLong() }