fun main() {
    repeat(readInt()) {
        val n = readInt()
        val a = readIntArray()
        val d = a.distinct()
        if (d.size == 1) {
            println("NO")
        } else {
            println("YES")
            val i1 = a.indices.find { a[it] == d[0] }!!
            val i2 = a.indices.find { a[it] == d[1] }!!
            for (i in a.indices) {
                if (i == i1) continue
                println("${i + 1} ${if (a[i] == a[i1]) i2 + 1 else i1 + 1}")
            }
        }
    }
}

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()