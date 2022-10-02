import java.lang.Integer.min

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        var (N, K) = readLine()!!.split(' ').map { it.toInt() }
        val A = readLine()!!.split(' ').map { it.toInt() }
        val IA = A.withIndex().sortedBy { -it.value }.toMutableList()
        (1 until N).forEach {
            val new = min(IA[it-1].value - 1, IA[it].value + K)
            K -= new - IA[it].value
            IA[it] = IndexedValue(IA[it].index, new)
        }

        repeat(N) {
            var change = K / N
            if (it < K%N) change++
            IA[it] = IndexedValue(IA[it].index, IA[it].value + change)
        }

        val D = IntArray(N) { 0 }
        repeat(N) {
            D[IA[it].index] = IA[it].value - A[IA[it].index]
        }
        println(D.joinToString(" ") { it.toString() })
    }
}