fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = Array(n) { readLine()!!.toCharArray() }
        readLine()
        val b = Array(n) { readLine()!!.toCharArray() }
        val graph = Array(4 * n) { mutableListOf<Int>() }
        val inverseRow = BooleanArray(n)
        val inverseCol = BooleanArray(n)
        for (case in 0 until 2) {
            inverseCol[0] = (case == 0)
            for (i in 0 until n) inverseRow[i] = (a[i][0] != b[i][0]) xor inverseCol[0]
            for (i in 1 until n) inverseCol[i] = (a[0][i] != b[0][i]) xor inverseRow[0]
            var different = false
            for (i in a.indices){
                for (j in b.indices){
                    different = different or ((a[i][j] != b[i][j]) xor inverseRow[i] xor inverseCol[j])
                }
            }
            if (!different) return@repeat println("YES")
        }
        println("NO")
    }
}