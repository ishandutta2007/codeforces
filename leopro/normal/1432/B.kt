fun main() {
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        println((n - 1) / 2)
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }