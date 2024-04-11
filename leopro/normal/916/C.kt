fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val prime = n.toBigInteger().nextProbablePrime().toInt()
    val edges = mutableListOf<Edge>()
    for (i in 1 until n - 1) {
        edges.add(Edge(i - 1, i, 1))
    }
    edges.add(Edge(n - 2, n - 1, prime - n + 2))
    for (i in 0 until n) {
        for (j in i + 2 until n) {
            if (edges.size == m) break
            edges.add(Edge(i, j, prime + 1))
        }
        if (edges.size == m) break
    }
    println("$prime $prime")
    println(edges.joinToString("\n"))
}

data class Edge(val u: Int, val v: Int, val w: Int) {
    override fun toString() = "${u + 1} ${v + 1} $w"
}