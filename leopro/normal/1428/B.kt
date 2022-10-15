fun main() {
    repeat(readInt()) {
        val n = readInt()
        val s = readLine()!!
        when {
            s.find { it == '<' } == null -> println(n)
            s.find {it == '>'} == null -> println(n)
            else -> println(s.indices.count { s[it] == '-' || s[(it + 1) % n]== '-' })
        }
    }
}

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }
fun readIntArray() = readInts().toIntArray()