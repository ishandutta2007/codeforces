fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val x = readLine()!!.split(' ').map { it.toInt() }
        for ((a,b) in x.zipWithNext()) {
            if ((a + b) % 2 == 0) return@repeat println("YES")
        }
        println("NO")
    }
}