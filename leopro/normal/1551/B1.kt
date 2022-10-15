fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val cnt = IntArray(26)
        for (c in s) cnt[c - 'a']++
        val cnt1 = cnt.indices.count { cnt[it] == 1 }
        val cnt2 = cnt.indices.count { cnt[it] > 1 }
        for (hint in 26 downTo 0) {
            if (cnt1 >= 2 * (hint - cnt2)) return@repeat println(hint)
        }
    }
}