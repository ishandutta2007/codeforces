fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val pairs = List(n) { readLine()!!.split(' ').let { (a, b, c) -> Set(a.reversed(), b.reversed(), c == "1") } }
        var range = 0..4_000_000
        for (set in pairs) {
            val q = set.possibleK()
            range = intersection(range, q)
        }
        println((range.last - range.first + 1).coerceAtLeast(0))
        println(range.joinToString(" "))
    }
}

fun intersection(p: IntRange, q: IntRange): IntRange {
    return maxOf(p.first, q.first)..minOf(p.last, q.last)
}

data class Set(val s: String, val t: String, val rhyme: Boolean) {
    fun possibleK(): IntRange {
        var length = 0
        while (s.length > length && t.length > length && s[length] == t[length]) length++
        return if (rhyme) {
            0..length
        } else {
            length + 1..4_000_000
        }
    }
}