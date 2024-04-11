private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

private fun readMatrix(n: Int) = Array(n) { readInts().toIntArray() }

private fun solve() {
    val n = readInt()
    val s = readLn().toCharArray()
    val a = readLn()
    var i = 0
    var ans = 0
    while(i < n - 3) {
        if (a[i] == '0') {
            i++
            continue
        }
        if ((i + 1 < n - 3 && a[i + 1] == '1') || (i + 3 < n - 3 && a[i + 3] == '1')) {
            println(-1)
            return
        }
        if (s[i] == ')') {
            s[i] = '('
            ans++
        }
        if (s[i + 3] == '(') {
            s[i + 3] = ')'
            ans++
        }
        if (i + 2 < n - 3 && a[i + 2] == '1') {
            if (s[i + 1] == '(') {
                s[i + 1] = ')'
                ans++
            }
        } else {
            if (s[i + 1] == s[i + 2]) ans++
        }
        i++
    }
    println(ans)
}

fun main() {
    val tt = readInt()
    repeat(tt) { solve() }
}