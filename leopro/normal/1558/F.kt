fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val a = readLine()!!.split(' ').map { it.toInt() - 1 }
        val pos = IntArray(a.size)
        for (i in a.indices) pos[a[i]] = i
        val countMinus = MaxTree(a.size)
        val exists = Tree01(a.size)
        var ans = 0
        var block = a.size
        for (x in pos.lastIndex downTo 1) {
            val idx = pos[x]
            if (idx < block) {
                countMinus.add(block, a.size, 1 - (block - (idx + 1)))
                for (i in idx + 1 until block) {
                    countMinus.set(i, (i + 1) % 2 + 1 - (i - (idx + 1)))
                    exists[i] = 1
                }
                block = idx
            } else {
                exists[idx] = 0
                countMinus.set(idx, countMinus.MINUS_INFINITY)
                countMinus.add(idx, a.size, 2)
            }
            ans = maxOf(ans, countMinus.getMax() + exists.getCount(0, a.size) - 1)
        }
        println(ans)
    }
}

class Tree01(size: Int) {
    private val n = 2 * size.takeHighestOneBit()
    private val h = n.countTrailingZeroBits()
    private val exists = IntArray(2 * n)

    private fun updateParents(i: Int) {
        for (shift in 1..h) {
            update(i shr shift)
        }
    }

    private fun update(i: Int) {
        exists[i] = exists[2 * i] + exists[2 * i + 1]
    }

    operator fun set(i: Int, e: Int) {
        exists[i + n] = e
        updateParents(i + n)
    }

    fun getCount(L: Int, R: Int): Int {
        var res = 0
        var l = L + n
        var r = R + n
        while (l < r) {
            if (l % 2 == 1) res += exists[l++]
            if (r % 2 == 1) res += exists[--r]
            l /= 2
            r /= 2
        }
        return res
    }
}

class MaxTree(size: Int) {
    private val n = 2 * size.takeHighestOneBit()
    private val h = n.countTrailingZeroBits()
    val MINUS_INFINITY = -1_000_000_000
    private val max = IntArray(2 * n) { MINUS_INFINITY }
    private val bias = IntArray(2 * n)

    private fun apply(i: Int, x: Int) {
        bias[i] += x
        max[i] += x
    }

    private fun push(i: Int) {
        apply(2 * i, bias[i])
        apply(2 * i + 1, bias[i])
        bias[i] = 0
    }

    private fun updateParents(i: Int) {
        for (shift in 1..h) {
            if (bias[i shr shift] == 0) update(i shr shift)
        }
    }

    private fun update(i: Int) {
        max[i] = maxOf(max[2 * i], max[2 * i + 1])
    }

    private fun pushParents(i: Int) {
        for (shift in h downTo 1) {
            push(i shr shift)
        }
    }

    fun add(L: Int, R: Int, x: Int) {
        var l = L + n
        var r = R + n
        pushParents(l)
        pushParents(r - 1)
        while (l < r) {
            if (l % 2 == 1) apply(l++, x)
            if (r % 2 == 1) apply(--r, x)
            l /= 2
            r /= 2
        }
        updateParents(L + n)
        updateParents(R + n - 1)
    }

    fun set(i: Int, x: Int) {
        pushParents(i + n)
        max[i + n] = x
        updateParents(i + n)
    }

    fun getMax() = max[1]
}