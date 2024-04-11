fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val N = readLine()!!.toInt()
        val A = readLine()!!.split(" ").map { it.toLong() }
        val ans = A.sorted().reversed().mapIndexed { id, v -> (id+1) * v }.max()
        println(ans)
    }
}