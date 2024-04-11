fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val s = readLine()!!
        var t = minOf(s.slice(0..0) + s.slice(0..0), s + s.reversed())
        for (j in 0 until s.lastIndex) {
            if (s[j] < s[j + 1]) {
                t = minOf(t, s.slice(0..j) + s.slice(0..j).reversed())
                break
            }
        }
        println(t)
    }
}