fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.sorted()
    val s = ArrayList<Int>()
    val t = ArrayList<Int>()
    var ok = true
    for (x in a) {
        if (s.isEmpty() || s.last() != x) {
            s += x
        } else if (t.isEmpty() || t.last() != x) {
            t += x
        } else {
            println("NO")
            return
        }
    }
    t.reverse()
    println("YES")
    println(s.size)
    println(s.joinToString(" "))
    println(t.size)
    println(t.joinToString(" "))
}