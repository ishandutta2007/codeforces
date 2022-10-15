fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val t = readLine()!!
        if (ok(s, t) || ok(s, t.reversed())) println("YES") else println("NO")
    }
}

fun ok(s: String, t: String): Boolean {
    for (i in (t.length + 2) / 2..t.length) {
        val length = t.length - i
        if (t.slice(i - 1 - length until i - 1) != t.slice(i until i + length).reversed()) continue
        if (t.slice(0 until i) in s) return true
    }
    return false
}