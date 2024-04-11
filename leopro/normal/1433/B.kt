fun main() {
    repeat(readInt()) {
        val n = readInt()
        val a = readIntArray()
        val l = a.indices.find { a[it] == 1 }!!
        val r = a.indices.findLast { a[it] == 1 }!!
        println(a.slice(l..r).count { it == 0 })
    }
}

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()