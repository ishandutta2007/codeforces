import kotlin.math.*

fun main() {
     var (n, m, k) = readLine()!!.split(' ').map(String::toInt)
     k = k - 1
     var cur = Array<Int>(n) { i -> 1000 * 1000 * 1000 }
     cur[k] = 0

     for (i in 0..m-1) {
        var (x, y) = readLine()!!.split(' ').map(String::toInt)
        x = x - 1
        y = y - 1
        
        val nx = min(cur[x] + 1, cur[y])
        val ny = min(cur[y] + 1, cur[x])
        cur[x] = nx
        cur[y] = ny
     }
     
     for (i in 0..n-1) {
        if (cur[i] > m) {
            cur[i] = -1
        }
     }
     println(cur.joinToString(separator=" "))
}