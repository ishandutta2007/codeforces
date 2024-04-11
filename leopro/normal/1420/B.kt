fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readInts().toIntArray()
        val highestBit = a.map { number -> (0..30).find { 1 shl it > number }!! - 1 }.toIntArray()
        val count = (0..30).map { degree -> highestBit.count { it == degree }.toLong() }
        println(count.map { it * (it - 1) / 2 }.sum())
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readLongs() = readLine()!!.split(' ').map { it.toLong() }