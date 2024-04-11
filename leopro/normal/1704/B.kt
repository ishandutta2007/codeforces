fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, x) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        fun go(i: Int): Int {
            var j = i
            var min = a[i]
            var max = a[i]
            do {
                j++
                if (j == a.size) return 0
                min = minOf(min, a[j])
                max = maxOf(max, a[j])
            } while (max - min <= 2 * x)
            return go(j) + 1
        }
        println(go(0))
    }
}