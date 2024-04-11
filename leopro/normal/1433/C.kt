fun main() {
    repeat(readInt()) {
        val n = readInt()
        val a = readIntArray()
        val max = a.max()
        val maxIndices = a.indices.filter { a[it] == max }
        val ans = maxIndices.find {
                    ((it - 1) in a.indices && a[it - 1] != max) ||
                    ((it + 1) in a.indices && a[it + 1] != max)
        }
        println(if (ans == null) -1 else ans + 1)
    }
}

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()