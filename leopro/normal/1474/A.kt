fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val b = readLine()!!.map { it - '0' }
        val a = IntArray(n)
        var prev = -1
        for (i in 0 until n) {
            if (b[i] == 0) {
                if (prev == -1 || prev == 2) prev = 0
                prev = 1 - prev
                a[i] = prev - b[i]
            } else {
                if (prev == -1 || prev == 0) prev = 1
                prev = 3 - prev
                a[i] = prev - b[i]
            }
        }
        println(a.joinToString(""))
    }
}