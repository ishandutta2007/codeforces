fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val t = readLine()!!
        for (times in 1 .. t.length) {
            val lcm = s * times
            if (t * (lcm.length / t.length) == lcm) return@repeat println(lcm)
        }
        println(-1)
    }
}

operator fun String.times(t: Int) = Array(t) { this }.joinToString("")