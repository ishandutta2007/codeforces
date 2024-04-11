fun main() {
    val Q = readLine()!!.toInt()
    repeat(Q) {
        val S = readLine()!!
        val T = readLine()!!
        var ok = true
        var i = 0
        var j = 0
        while (i < S.length && j < T.length && ok) {
            if (S[i] == T[j]) {
                i++
                j++
            } else if (S[i] == '-' && i+1 < S.length && S[i+1] == '-' && T[j] == '+') {
                i+=2
                j++
            } else {
                ok = false
            }
        }

        println(if (ok && i == S.length && j == T.length) "YES" else "NO")
    }
}