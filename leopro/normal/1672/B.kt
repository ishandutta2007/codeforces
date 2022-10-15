fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        if (s.last() == 'A') return@repeat println("NO")
        var cur = 0
        for (c in s) {
            if (c == 'A') cur++ else cur--
            if (cur < 0) return@repeat println("NO")
        }
        println("YES")
    }
}