fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
        if (n % 2 == 0 && m % 2 == 1 && (k % 2 != 0 || k + (n / 2) > n * m / 2)) return@repeat println("NO")
        if (n % 2 == 0 && k % 2 != 0) return@repeat println("NO")
        if (n % 2 == 1 && (k % 2 != (m / 2) % 2 || k < (m / 2))) return@repeat println("NO")

        val pitch = List(n) { CharArray(m) { 'N' } }
        var cur = 0
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (i % 2 == 0) pitch[i][j] = 'U' else pitch[i][j] = 'D'
            }
        }
        if (n % 2 == 1) {
            for (j in 0 until m) if (j % 2 == 0) pitch.last()[j] = 'L' else pitch.last()[j] = 'R'
            cur = m / 2
        }
        fun flip(i: Int, j: Int): Boolean {
            if (i + 1 >= pitch.size || j + 1 >= pitch[i].size) return false
            if (pitch[i][j] == 'U' && pitch[i][j + 1] == 'U' && pitch[i + 1][j] == 'D' && pitch[i + 1][j + 1] == 'D') {
                pitch[i][j] = 'L'
                pitch[i + 1][j] = 'L'
                pitch[i][j + 1] = 'R'
                pitch[i + 1][j + 1] = 'R'
                return true
            }
            return false
        }
        out@for (i in 0 until n) {
            for (j in 0 until m) {
                if (cur == k) break@out
                if (flip(i, j)) cur += 2
            }
        }
        println("YES")
        val ans = List(n) { CharArray(m) { 'z' } }
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (ans[i][j] == 'z') {
                    if (pitch[i][j] == 'U') {
                        ans[i][j] = 'a' + (i + j) % 25
                        ans[i + 1][j] = 'a' + (i + j) % 25
                    } else if (pitch[i][j] == 'L') {
                        ans[i][j] = 'a' + (i + j) % 25
                        ans[i][j + 1] = 'a' + (i + j) % 25
                    }
                }
            }
        }
        println(ans.joinToString("\n") { it.joinToString("") })
    }
}