import kotlin.math.*

fun main() {
    repeat(readLine()!!.toInt()) {
        var (n, k) = readLine()!!.split(" ").map{it.toLong()}
        val s = StringBuilder(readLine())
        val a = s.split('0').map{it.length}.toIntArray()
        for(i in 0 until a.size - 1) {
            val mvCnt = min(k, a[i].toLong()).toInt()
            k -= mvCnt
            a[i] -= mvCnt
            a[i+1] += mvCnt
        }
        val ans = StringBuilder()
        for(i in a.indices) {
            repeat(a[i]) {
                ans.append(1)
            }
            if (i < a.lastIndex) ans.append(0)
        }
        println(ans)
    }
}