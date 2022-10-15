fun main() {
    for (test in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val count = Array(256) { 0 }
        for (i in 0 until n) {
            for (c in readLine()!!) {
                count[c.toInt()]++;
            }
        }
        var ans = true
        for (cnt in count) {
            ans = ans && cnt % n == 0
        }
        println(if (ans) "YES" else "NO")
    }

}