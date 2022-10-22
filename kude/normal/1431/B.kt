fun main() {
    var tt = readLine()!!.toInt()
    repeat(tt) {
        val s = readLine()!!
        var now = 0
        var ans = 0
        for(c in s) {
            now += if (c == 'w') 2 else 1
            if (now >= 2) {
                ans += 1
                now = 0
            }
        }
        println(ans)
    }
}