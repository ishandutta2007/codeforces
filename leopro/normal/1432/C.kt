fun main() {
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        println((readInts().sum() + n - 1) / n)
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }