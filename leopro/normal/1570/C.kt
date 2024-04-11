fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }.withIndex().sortedByDescending { it.value }
    println(a.mapIndexed { x, (_, ai) -> ai * x + 1 }.sumOf { it })
    println(a.map { it.index + 1 }.joinToString(" "))
}