fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.sorted()
    var nxt = 1
    var ans = 0
    for (x in a) {
        if (x - 1 >= nxt) {
            ans++
            nxt = x
        } else if (x + 1 >= nxt) {
            ans++
            nxt++
        }
    }
    println(ans)
}