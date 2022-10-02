fun main() {
    val N = readLine()!!.toInt()
    val A = readLine()!!.split(" ").map { it.toInt() }
    var c = 0
    var d = 0
    var ans = 0
    A.forEach {
        if (it > c) {
            d = c
            c = it
        } else if (it > d) {
            d = it
        } else if (it < d) {
            ans += 1
        }
    }
    println(ans)
}