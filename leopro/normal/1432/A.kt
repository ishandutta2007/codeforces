fun main() {
    repeat(readLine()!!.toInt()){
        val (a, b) = readInts()
        println(a + b)
    }
}

fun readInts() = readLine()!!.split(' ').map { it.toInt() }