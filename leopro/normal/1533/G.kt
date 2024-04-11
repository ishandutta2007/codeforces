data class Biome(val i: Int, val j: Int, val id: Int)

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val biomes = List(n) { i -> readLine()!!.split(' ').mapIndexed { j, id -> Biome(i, j, id.toInt()) } }
        var start: Pair<Int, Int>? = null
        val visited = List(n) { BooleanArray(m) }
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (biomes[i][j].id != 0) start = i to j else visited[i][j] = true
            }
        }
        val sequence = mutableListOf<Int>()
        fun dfs(cur: Pair<Int, Int>) {
            sequence.add(cur.run { biomes[first][second].id })
            fun relax(i: Int, j: Int): Boolean {
                if (i !in visited.indices || j !in visited[i].indices || visited[i][j]) return false
                visited[i][j] = true
                return true
            }
            if (relax(cur.first, cur.second + 1)) dfs(cur.first to cur.second + 1).also { sequence.add(cur.run { biomes[first][second].id }) }
            if (relax(cur.first + 1, cur.second)) dfs(cur.first + 1 to cur.second).also { sequence.add(cur.run { biomes[first][second].id }) }
            if (relax(cur.first, cur.second - 1)) dfs(cur.first to cur.second - 1).also { sequence.add(cur.run { biomes[first][second].id }) }
            if (relax(cur.first - 1, cur.second)) dfs(cur.first - 1 to cur.second).also { sequence.add(cur.run { biomes[first][second].id }) }
        }
        dfs(start!!)
        if (visited.any { it.any { !it } }) return@repeat println(-1)
        println("${sequence.size / 2} ${sequence.size / 2}")
        for (i in 0 until sequence.size / 2) {
            for (j in 0 until sequence.size / 2) {
                print(sequence[i + j])
                print(" ")
            }
            println()
        }
    }
}