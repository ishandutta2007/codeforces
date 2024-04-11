fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val h = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
        for (i in 0 until n){
            if (h[i] < i) return@repeat println("NO")
            if (i + 1 < n) h[i + 1] += h[i] - i
        }
        println("YES")
    }
}