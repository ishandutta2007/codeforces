fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }
    val ans = a.filterIndexed { index, value -> (index + 1 until a.size).all { a[it] != value } }
    println(ans.size)
    println(ans.joinToString(" "))
}