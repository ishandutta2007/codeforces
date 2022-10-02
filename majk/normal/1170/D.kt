fun main() {
    val M = readLine()!!.toInt()
    val B = readLine()!!.split(" ").map { it.toInt() }
    val C = B.count { it == -1 }
    val A = Array(C) { mutableListOf<Int>() }
    var E = mutableListOf<Int>()
    repeat(C) { E.add(it) }
    var i = 0
    while (i < M) {
        val F = mutableListOf<Int>()
        E.forEach {
            if (B[i] != -1) {
                A[it].add(B[i])
                F.add(it)
            }
            ++i
        }
        E = F
    }

    println(C)
    A.forEach {
        println("${it.size} ${it.joinToString(" ") { it.toString() }}")
    }

}