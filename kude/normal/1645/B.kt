fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var idx = 0
    var i = 1
    val ans = ArrayList<Char>()
    while(idx < n) {
        ans += s[idx]
        idx += i++
    }
    println(ans.joinToString(""))
}