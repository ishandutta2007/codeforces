fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
    val f = mutableListOf<Int>()
    val s = mutableListOf<Int>()
    for (x in a) {
        if (x == f.lastOrNull()) s.add(x) else f.add(x)
    }
    if (s.distinct().size != s.size) return println("NO")
    println("YES")
    println(f.size)
    println(f.joinToString(" "))
    println(s.size)
    println(s.reversed().joinToString(" "))
}