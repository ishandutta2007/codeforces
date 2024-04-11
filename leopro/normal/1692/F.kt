fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() % 10 }
        val cnt = IntArray(10)
        for (x in a) cnt[x]++
        val r = 0 until 10
        for (x in r) {
            for (y in r) {
                for (z in r) {
                    if ((x + y + z) % 10 == 3) {
                        cnt[x]--
                        cnt[y]--
                        cnt[z]--
                        if (cnt.all { it >= 0 }) return@repeat println("YES")
                        cnt[x]++
                        cnt[y]++
                        cnt[z]++
                    }
                }
            }
        }
        println("NO")
    }
}