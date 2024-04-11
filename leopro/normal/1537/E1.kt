fun main() {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    val s = readLine()!!
    var ans: String? = null
    for (length in 1..n) {
        val attempt = CharArray(k) { s[it % length] }.joinToString("")
        if (ans == null || ans > attempt) ans = attempt
    }
    println(ans)
}