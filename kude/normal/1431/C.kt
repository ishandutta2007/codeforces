fun main() {
    var tt = readLine()!!.toInt()
    repeat(tt) {
        val (n, k) = readLine()!!.split(" ").map{it.toInt()}
        val p = readLine()!!.split(" ").map{it.toInt()}.toIntArray()
        val s = ArrayList<Int>()
        s.add(0)
        for(pi in p) {
            val si = s.last() + pi
            s.add(si)
        }
        var ans = 0
        for(i in p.indices) {
            val cnt = (n - i) / k
            val t = s[i + cnt] - s[i]
            if (ans < t) ans = t
        }
        println(ans)
    }
}