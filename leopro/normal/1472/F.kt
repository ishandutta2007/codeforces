import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val cells = List(m) { readLine()!!.split(' ').map { it.toInt() } }.map { it.first() to it.last() }
        val columns = cells.map { it.second }.sorted().toIntArray()
        val close = IntArray(columns.size) { columns[0] % 2 }
        for (i in 1 until close.size) {
            if (columns[i] == columns[i - 1]) close[i] = close[i - 1]
            if (columns[i] > columns[i - 1]) close[i] = (close[i - 1] or 1) + (3 - columns[i] % 2)
        }
        val board = Array(3) { BooleanArray(close.last() + 1) }
        board[2].fill(true)
        for (cell in cells) {
            board[cell.first - 1][close[columns.binarySearch(cell.second)]] = true
        }
        for (j in board[0].indices) {
            for (i in 0 until 2) {
                if (board[i][j]) continue
                if (!board[i + 1][j]){
                    board[i][j] = true
                    board[i + 1][j] = true
                    continue
                }
                if (j + 1 in board[i].indices && !board[i][j + 1]){
                    board[i][j] = true
                    board[i][j + 1] = true
                    continue
                }
                return@repeat println("NO")
            }
        }
        println("YES")
    }
}