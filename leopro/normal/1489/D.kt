fun main() {
    val n = readLine()!!.toInt()
    val lines = List(n) { readLine()!! }.sortedBy { it.length }
    if ((1 until n).all { lines[it - 1] in lines[it] }) println("YES\n${lines.joinToString("\n")}") else println("NO")
}