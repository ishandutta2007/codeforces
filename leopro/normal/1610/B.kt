fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        if (kalindrome(a, -1)) return@repeat println("YES")
        var idx = 0
        for (i in a.indices) {
            if (a[i] != a[a.lastIndex - i]) {
                idx = i
                break
            }
        }
        if (kalindrome(a, a[idx])) return@repeat println("YES")
        if (kalindrome(a, a[a.lastIndex - idx])) return@repeat println("YES")
        if (kalindrome(a, a.first())) return@repeat println("YES") // should be unused
        println("NO")
    }
}

fun kalindrome(a: IntArray, x: Int): Boolean {
    val f = a.filter { it != x }
    for (i in 0 until (f.size / 2)) {
        if (f[i] != f[f.lastIndex - i]) return false
    }
    return true
}