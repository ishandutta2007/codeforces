fun main() {
    repeat(readLine()!!.toInt()) {
        val (x1, p1) = readLine()!!.split(' ').map { it.toInt() }
        val (x2, p2) = readLine()!!.split(' ').map { it.toInt() }
        val len1 = x1.toString().length + p1
        val len2 = x2.toString().length + p2
        if (len1 != len2) {
            println(if (len1 < len2) "<" else ">")
        } else {
            val mn = minOf(p1, p2)
            val y1 = x1.toString().padEnd(len1 - mn, '0')
            val y2 = x2.toString().padEnd(len1 - mn, '0')
            if (y1 == y2) return@repeat println("=")
            println(if (y1 < y2) "<" else ">")
        }
    }
}