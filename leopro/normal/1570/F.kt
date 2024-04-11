fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }
    val a = List(n) { readLine()!!.split(' ').map { it.toInt() }.toIntArray() }
    val operations = mutableListOf<Cell>()
    for (i in 0 until a.lastIndex) {
        for (j in 0 until a[i].lastIndex) {
            if (listOf(a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1]).all { it == 1 }) {
                operations.add(Cell(i, j))
            }
        }
    }
    for ((i, j) in operations) {
        a[i][j] = 0
        a[i][j + 1] = 0
        a[i + 1][j] = 0
        a[i + 1][j + 1] = 0
    }
    if (a.any { it.any { it == 1 } }) return println(-1)
    println(operations.size)
    println(operations.joinToString("\n"))
}

data class Cell(val i: Int, val j: Int) {
    override fun toString() = "${i + 1} ${j + 1}"
}