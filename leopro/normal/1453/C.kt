import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = Array(n) { readLine()!!.toCharArray() }
        for (d in 0 until 10) {
            var ans = 0
            val rows = a.indices.filter { idx -> a.indices.any { a[idx][it] == '0' + d } }
            val cols = a.indices.filter { idx -> a.indices.any { a[it][idx] == '0' + d } }
            if (rows.isEmpty()) {
                print("0 ")
                continue
            }
            for (row in 0 until n) {
                if (a.indices.find { a[row][it] == '0' + d } == null) continue
                val lowest = a.indices.find { a[row][it] == '0' + d }!!
                val highest = a.indices.findLast { a[row][it] == '0' + d }!!
                val length = maxOf(row - rows.first(), rows.last() - row)
                ans = maxOf(ans, (n - 1 - lowest) * length)
                ans = maxOf(ans, (highest) * length)
                val height = maxOf(n - 1 - row, row)
                ans = maxOf(ans, (highest - lowest) * height)
            }
            for (col in 0 until n) {
                if (a.indices.find { a[it][col] == '0' + d } == null) continue
                val lowest = a.indices.find { a[it][col] == '0' + d }!!
                val highest = a.indices.findLast { a[it][col] == '0' + d }!!
                val length = maxOf(col - cols.first(), cols.last() - col)
                ans = maxOf(ans, (n - 1 - lowest) * length)
                ans = maxOf(ans, (highest) * length)
                val height = maxOf(n - 1 - col, col)
                ans = maxOf(ans, (highest - lowest) * height)
            }
            print("$ans ")
        }
        println()
    }
}