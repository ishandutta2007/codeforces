fun main() {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    val s = readLine()!!
    val sufArray = SufArray(s)
    var ans = 1
    for (length in 2..n) {
        if (s[length - 1] != s[(length - 1) % ans]) {
            if (s[length - 1] < s[(length - 1) % ans]) ans = length
            if (s[length - 1] > s[(length - 1) % ans]) return println(CharArray(k) { s[it % ans] })
        }
        if (length % ans == 0) continue
        if (sufArray[length % ans] > sufArray[0]) ans = length
    }
    println(CharArray(k) { s[it % ans] })
}

class SufArray(private val s: String) {
    private var c: IntArray

    operator fun get(i: Int) = c[i]

    init {
        val n = s.length
        c = IntArray(n) { s[it] - 'a' }
        val ord = IntArray(n)
        val cnt = IntArray(maxOf(n, 26))
        for (i in 0 until n) cnt[c[i]]++
        val p = IntArray(cnt.size + 1)
        for (i in cnt.indices) p[i + 1] = p[i] + cnt[i]
        for (i in 0 until n) {
            ord[p[c[i]]++] = i
        }
        for (len in generateSequence(1) { it * 2 }.takeWhile { it < n }) {
            val shifted = IntArray(n)
            for (i in 0 until n) {
                shifted[i] = (ord[i] - len + n) % n
            }
            cnt.fill(0)
            for (i in 0 until n) cnt[c[i]]++
            p.fill(0)
            for (i in cnt.indices) p[i + 1] = p[i] + cnt[i]
            for (i in shifted) {
                ord[p[c[i]]++] = i
            }
            var cur = -1
            val newC = IntArray(n)
            for (i in 0 until n) {
                if (i == 0 || (c[ord[i]] != c[ord[i - 1]] || c[(ord[i] + len) % n] != c[(ord[i - 1] + len) % n])) {
                    cur++
                }
                newC[ord[i]] = cur
            }
            c = newC
        }
    }
}