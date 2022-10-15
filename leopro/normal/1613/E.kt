fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val grid = List(n) { readLine()!!.toCharArray() }
        val l = Cell(
            (0 until n).find { i -> (0 until m).any { j -> grid[i][j] == 'L' } }!!,
            (0 until m).find { j -> (0 until n).any { i -> grid[i][j] == 'L' } }!!
        )
        val temptations = List(n) { IntArray(m) }
        for (i in 0 until n) {
            for (j in 0 until m) {
                for (neighbour in Cell(i, j).neighbours().filter { (ni, nj) -> ni in 0 until n && nj in 0 until m }) {
                    if (grid[neighbour.i][neighbour.j] in listOf('.', 'L')) temptations[i][j]++
                }
            }
        }
        val ok = List(n) { BooleanArray(m) }
        ok[l.i][l.j] = true
        val dfs = mutableListOf(l)
        while (dfs.isNotEmpty()) {
            val cell = dfs.removeLast()
            for (neighbour in cell.neighbours().filter { (ni, nj) -> ni in 0 until n && nj in 0 until m }) {
                if (grid[neighbour.i][neighbour.j] == '.' && !ok[neighbour.i][neighbour.j]) {
                    if (--temptations[neighbour.i][neighbour.j] <= 1) {
                        dfs.add(neighbour)
                        ok[neighbour.i][neighbour.j] = true
                    }
                }
            }
        }
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (ok[i][j] && grid[i][j] == '.') {
                    grid[i][j] = '+'
                }
            }
        }
        println(grid.joinToString("\n") { it.joinToString("") })
    }
}

data class Cell(val i: Int, val j: Int) {
    fun neighbours() = listOf(Cell(i - 1, j), Cell(i, j - 1), Cell(i + 1, j), Cell(i, j + 1))
}