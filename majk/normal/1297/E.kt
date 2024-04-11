import java.lang.Integer.min

fun main() {
    val T = readLine()!!.toInt()
    repeat(T) { t ->
        val (N, K) = readLine()!!.split(' ').map { it.toInt() }
        val E = (0 until N).map { mutableListOf<Int>() }
        repeat(N-1) {
            val (A, B) = readLine()!!.split(' ').map { it.toInt() }
            E[A-1].add(B-1)
            E[B-1].add(A-1)
        }
        if (K == 1) {
            println("Yes")
            println("1")
            println("1")
        } else {
            val U = BooleanArray(N) { true }
            val Q = mutableListOf<Int>()
            val C = IntArray(N) { E[it].size }
            repeat(N) { if (C[it] == 1) Q.add(it) }

            if (Q.size < K) {
                println("No")
            } else {
                println("Yes")
                for (i in 0 until N) {
                    if (Q.size - i == K) {
                        println(U.count { it })
                        println(U.withIndex().filter { it.value }.joinToString(" ") { (it.index + 1).toString() })
                        break
                    }

                    val q = Q[i]
                    U[q] = false
                    for (d in E[q]) {
                        if (U[d]) {
                            C[d]--
                            if (C[d] == 1) Q.add(d)
                        }
                    }
                }
            }
        }
    }
}