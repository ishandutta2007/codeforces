fun main() {
    val (h, w) = readLine()!!.split(' ').map { it.toInt() }
    val cake = List(h) { readLine()!!.map { it == '*' } }
    var i = 0
    var j = 0
    var ans = 0
    while (i + 1 < h || j + 1 < w){
        ans += if (cake[i][j]) 1 else 0
        if (i + 1 == h) {
            j++
        } else {
            if (j + 1 == w) {
                i++
            } else {
                if (cake[i + 1][j]) i++ else j++
            }
        }
    }
    println(ans + if (cake[i][j]) 1 else 0)
}