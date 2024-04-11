fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val a = readLine()!!
        val b = readLine()!!
        if (a == b) return@repeat println("YES")
        var end = 0
        while (a.getOrNull(a.lastIndex - end) == b.getOrNull(b.lastIndex - end)) {
            end++
        }
        if (end == b.length) return@repeat println("YES")
        if (end != b.length - 1) return@repeat println("NO")
        if (a.slice(0 until a.length - end).all { it != b[0] }) return@repeat println("NO")
        println("YES")
    }
}