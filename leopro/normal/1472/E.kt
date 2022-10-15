fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val friends =
            List(n) { readLine()!!.split(' ').map { it.toInt() }.sorted() }.map { it.first() to it.last() }
                .withIndex()
                .sortedWith(
                    compareBy({ it.value.first }, { it.value.second })
                )
        val minSecond = IntArray(n) { it }
        for (i in 1 until n) {
            if (friends[minSecond[i]].value.second > friends[minSecond[i - 1]].value.second) {
                minSecond[i] = minSecond[i - 1]
            }
        }
        val lessFirst = IntArray(n) { it - 1 }
        for (i in 1 until n) {
            if (friends[i].value.first == friends[i - 1].value.first) {
                lessFirst[i] = lessFirst[i - 1]
            }
        }
        val ans = IntArray(n)
        for (i in 0 until n) {
            val suf = lessFirst[i]
            if (suf < 0) {
                ans[friends[i].index] = -2
                continue
            }
            val best = minSecond[suf]
            if (friends[best].value.first < friends[i].value.first &&
                friends[best].value.second < friends[i].value.second
            ) {
                ans[friends[i].index] = friends[best].index
            } else {
                ans[friends[i].index] = -2
            }
        }
        println(ans.map { it + 1 }.joinToString(" "))
    }
}