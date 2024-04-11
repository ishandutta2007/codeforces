fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        if (a.any { it < 0 }) return@repeat println("NO")
        println("YES")
        println(101)
        println((0..100).joinToString(" "))
    }
}