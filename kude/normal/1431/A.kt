fun main() {
    var tt = readLine()!!.toInt()
    repeat(tt) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map{it.toLong()}.toLongArray()
        a.sort()
        var ans: Long = 0
        for((i, x) in a.withIndex()) {
            val t = x * (n - i)
            ans = if (t > ans) t else ans
        }
        println(ans)
    }
}