fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val matrix = Array(n) { readLine()!!.toCharArray() }
        if (m % 2 == 1) {
            println("YES")
            repeat(m + 1) { print("${it % 2 + 1} ") }
            return@repeat println()
        }
        for (i in 0 until n) {
            for (j in 0 until n) {
                if (i != j && matrix[i][j] == matrix[j][i]) {
                    println("YES")
                    repeat(m + 1) { print("${(if (it % 2 == 0) i else j) + 1} ") }
                    return@repeat println()
                }
            }
        }
        val aabbWay = Array(n) { BooleanArray(n) }
        for (i in matrix.indices) {
            val nextA = (0 until n).filter { matrix[i][it] == 'a' }
            val prevA = (0 until n).filter { matrix[it][i] == 'a' }
            val nextB = (0 until n).filter { matrix[i][it] == 'b' }
            val prevB = (0 until n).filter { matrix[it][i] == 'b' }
            for (u in nextA) {
                for (v in prevA) {
                    if (aabbWay[v][u]) return@repeat answer(matrix, u, v, m)
                    if (aabbWay[u][v]) return@repeat answer(matrix, u, v, m)
                    aabbWay[u][v] = true
                    aabbWay[v][u] = true
                }
            }
            for (u in nextB) {
                for (v in prevB) {
                    if (aabbWay[v][u]) return@repeat answer(matrix, u, v, m)
                    if (aabbWay[u][v]) return@repeat answer(matrix, u, v, m)
                    aabbWay[u][v] = true
                    aabbWay[v][u] = true
                }
            }
        }
        println("NO")
    }
}

fun answer(matrix: Array<CharArray>, u: Int, v: Int, m: Int) {
    println("YES")
    val via = matrix.indices.find { matrix[u][it] == matrix[it][v] }!!
    if (m % 4 == 0) {
        repeat(m + 1) { print("${intArrayOf(via, u, via, v)[it % 4] + 1} ") }
    } else {
        repeat(m + 1) { print("${intArrayOf(u, via, v, via)[it % 4] + 1} ") }
    }
    println()
}