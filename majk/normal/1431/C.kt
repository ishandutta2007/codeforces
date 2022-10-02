fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val (N, K) = readLine()!!.split(' ').map { it.toInt() }
        val P = readLine()!!.split(' ').map { it.toInt() }
        println((1..N).map { x ->
            val cnt = x / K
            P.subList(N-x, N-x+cnt).sum()
        }.max())
    }
}