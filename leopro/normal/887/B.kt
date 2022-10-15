fun main() {
    val n = readLine()!!.toInt()
    val a = List(n) { readLine()!!.split(' ').map { it.toInt() }.toIntArray() }
    val ok = HashSet<List<Int>>()
    for (mask in 1 until (1 shl n)) {
        val choice = (0 until n).filter { mask and (1 shl it) != 0 }.map { a[it] }
        for (c in 0 until (1 shl (3 * choice.size))) {
            val eights = (choice.indices).map { (c shr (3 * it)) and 0b111 }
            if (eights.any { it >= 6 }) continue
            ok.add(List(choice.size) { choice[it][eights[it]] }.sorted())
        }
    }
    var x = 1
    while (ok.contains(x.toString().map { it - '0' }.sorted())) x++
    println(x - 1)
}