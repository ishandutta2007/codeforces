fun main() {
    val (N, M) = readLine()!!.split(" ").map { it.toInt() }
    val E = Array(N) { mutableSetOf<Pair<Int,Int>>() }
    repeat(M) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        E[a-1].add(it to b-1)
        E[b-1].add(it to a-1)
    }

    val Ans = mutableListOf<List<Int>>()
    repeat(N) {
        if (E[it].isNotEmpty()) {
            val cur = mutableListOf(it)
            val idx = mutableSetOf(it)
            while (true) {
                val u = cur.last()
                if (E[u].isEmpty()) {
                    if (cur.size == 1) break

                    println("NO")
                    return
                }

                val p = E[u].first()
                val v = p.second
                if (v == u) {
                    E[u].remove(p)
                    Ans.add(listOf(u, u))
                    continue
                }
                E[u].remove(p)
                E[v].remove(p.first to u)
                if (idx.contains(v)) {
                    val mine = mutableListOf(v)
                    do {
                        mine.add(cur.last())
                        idx.remove(cur.last())
                        cur.removeAt(cur.size - 1)
                    } while (cur.last() != v)
                    mine.add(v)
                    Ans.add(mine)

                } else {
                    cur.add(v)
                    idx.add(v)
                }
            }
        }
    }

    println("YES")
    println(Ans.size)
    Ans.forEach {
        println("${it.size} ${it.joinToString(" ") { (it+1).toString() }}")
    }
}