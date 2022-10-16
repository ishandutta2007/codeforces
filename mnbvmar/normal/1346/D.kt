import kotlin.math.*

fun main() {
    val t = readLine()!!.toInt()
    for (tid in 1..t) {
         val (n, m) = readLine()!!.split(' ').map(String::toInt)
         var ui = Array<Int>(m) { i -> 0 }
         var vi = Array<Int>(m) { i -> 0 }
         var ci = Array<Int>(m) { i -> 0 }
         var vx = Array<Int>(n) { i -> -1100 * 1000 * 1000 }
         for (i in 0..m-1) {
            var (u, v, c) = readLine()!!.split(' ').map(String::toInt)
            u = u - 1
            v = v - 1
            ui[i] = u
            vi[i] = v
            ci[i] = c
            vx[u] = max(vx[u], c)
            vx[v] = max(vx[v], c)
         }
         
         var ok = true
         for (i in 0..m-1) {
            val c = min(vx[ui[i]], vx[vi[i]])
            if (ci[i] != c) {
                ok = false
            }
         }
         
         if (!ok) {
            println("NO")
         } else {
            println("YES")
            println(vx.joinToString(separator=" "))
         }
    }
}