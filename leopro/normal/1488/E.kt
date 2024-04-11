class SegmentTree(private val n: Int) {
    private val max = IntArray(2 * n)
    fun set(i: Int, v: Int) {
        max[i + n] = v
        for (idx in generateSequence((i + n) / 2) { it / 2 }.takeWhile { it > 0 }) {
            max[idx] = maxOf(max[2 * idx], max[2 * idx + 1])
        }
    }

    fun at(i: Int) = get(i, i + 1)

    fun get(lq: Int, rq: Int): Int {
        var l = lq + n
        var r = rq + n
        var mx = 0
        while (l < r) {
            if (l % 2 == 1) mx = maxOf(mx, max[l++])
            if (r % 2 == 1) mx = maxOf(mx, max[--r])
            l /= 2
            r /= 2
        }
        return mx
    }
}

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() - 1 }.toIntArray()
        val indices = List(n) { mutableListOf<Int>() }
        for (i in a.indices) indices[a[i]].add(i)
        val next = IntArray(n) { n }

        for (v in 0 until n) {
            for (i in indices[v].indices) {
                if (i < indices[v].lastIndex) next[indices[v][i]] = indices[v][i + 1]
            }
        }

        val max = SegmentTree(n)
        var ans = 0
        for (i in a.indices) {
            ans = maxOf(ans, 2 * max.get(i + 1, n) + 1)
            if (next[i] !in i until n) {
                continue
            }
            val r = max.get(next[i] + 1, n) + 1
            if (max.at(next[i]) < r) max.set(next[i], r)
            ans = maxOf(ans, 2 * max.get(i + 1, n))
        }
        println(ans)
    }
}