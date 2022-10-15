fun main() {
    val ans = mutableListOf<Boolean>()
    repeat(readLine()!!.toInt()) {
        var (a, b, ab, ba) = readLine()!!.split(' ').map { it.toInt() }
        val s = readLine()!!
        if (s.count { it == 'A' } != a + ab + ba) return@repeat ans.add(false).let { }
        if (s.count { it == 'B' } != b + ab + ba) return@repeat ans.add(false).let { }
        val ababa = mutableListOf<Int>()
        val abab = mutableListOf<Int>()
        val baba = mutableListOf<Int>()
        val babab = mutableListOf<Int>()
        val alter = BooleanArray(s.length - 1) { s[it] != s[it + 1] }
        for (i in alter.indices) {
            if (!alter[i]) continue
            if (i == 0 || !alter[i - 1]) {
                var j = i
                while (j + 1 < alter.size && alter[j + 1]) j++
                if (j % 2 == i % 2 && s[i] == 'A') abab.add((j - i + 2) / 2)
                else if (j % 2 == i % 2 && s[i] == 'B') baba.add((j - i + 2) / 2)
                else if (s[i] == 'A') ababa.add((j - i + 2) / 2)
                else if (s[i] == 'B') babab.add((j - i + 2) / 2)
            }
        }
        abab.sortDescending()
        baba.sortDescending()
        while (ab > 0 && abab.isNotEmpty()) {
            val min = minOf(ab, abab.last())
            ab -= min
            abab[abab.lastIndex] -= min
            if (abab.last() == 0) abab.removeLast()
        }
        while (ba > 0 && baba.isNotEmpty()) {
            val min = minOf(ba, baba.last())
            ba -= min
            baba[baba.lastIndex] -= min
            if (baba.last() == 0) baba.removeLast()
        }
        if (ba == 0) {
            ab -= baba.sumOf { it - 1 }
            ab -= ababa.sumOf { it } + babab.sumOf { it }
            ans.add(ab <= 0)
        } else if (ab == 0) {
            ba -= abab.sumOf { it - 1 }
            ba -= ababa.sumOf { it } + babab.sumOf { it }
            ans.add(ba <= 0)
        } else ans.add(ba + ab <= ababa.sumOf { it } + babab.sumOf { it })
    }
    println(ans.joinToString("\n") { if (it) "YES" else "NO" })
}