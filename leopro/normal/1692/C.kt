fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val n = 8
        val a = List(n) { readLine()!!.toCharArray() }
        for (i in 0 until n) {
            for (j in 0 until n) {
                val b = List(n) { x -> CharArray(n) { y -> if (x - y == i - j || x + y == i + j) '#' else '.' } }
                var equal = true
                for (x in 0 until n) {
                    for (y in 0 until n) {
                        if (a[x][y] != b[x][y]) equal = false
                    }
                }
                if (equal) return@repeat println("${i.plus(1)} ${j.plus(1)}")
            }
        }
    }
}