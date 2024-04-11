import java.lang.Math.abs

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val N = readLine()!!.toInt()
        val A = readLine()!!.split(' ').map { it.toInt() }
        val U = BooleanArray(N) { A[it] > 0 }
        val Min = A.withIndex().filter { it.value != 0 }.minBy { abs(it.value) }
        U[Min!!.index] = A[Min.index] < 0
        val ans = A.filter { it > 0 }.sum() - abs(Min.value)
        println(ans)
        println(U.joinToString("") { if (it) "1" else "0" })
    }
}