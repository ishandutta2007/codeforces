import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
 
const val MOD = 1000000007L
const val P = 3L
 
fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val s = jin.readLine()
    val hashes = LongArray(n + 1)
    val sums = IntArray(n + 1)
    val sum1s = IntArray(n + 1)
    for (j in 1..n) {
        if (j >= 2 && s[j - 1] == '1' && s[j - 2] == '1') {
            hashes[j] = hashes[j - 2]
            sums[j] = sums[j - 2]
        } else {
            hashes[j] = ((P * hashes[j - 1]) + (s[j - 1] - '0').toLong()) % MOD
            sums[j] = sums[j - 1] + 1
        }
        sum1s[j] = sum1s[j - 1] + (s[j - 1] - '0')
    }
    val next = IntArray(n + 1)
    next[n] = n
    for (j in n - 1 downTo 0) {
        if (s[j] == '1') {
            next[j] = next[j + 1]
        } else {
            next[j] = j
        }
    }
    val THREE_POW = LongArray(n + 2)
    THREE_POW[0] = 1L
    for (j in 1..n + 1) {
        THREE_POW[j] = (P * THREE_POW[j - 1]) % MOD
    }
    fun hash(x: Int, y: Int): Long {
        val xn = next[x]
        if (xn >= y) {
            return when ((x + y) % 2) {
                0 -> 0L
                1 -> 1L
                else -> -1L
            }
        } else {
            //println("x = $x, y = $y, xn = $xn")
            var res = hashes[y] - (hashes[xn] * THREE_POW[sums[y] - sums[xn]])
            res %= MOD
            if ((x + xn) % 2 == 1) {
                res += THREE_POW[sums[y] - sums[xn]]
                res %= MOD
            }
            res += MOD
            res %= MOD
            return res
        }
    }
    /*val ps = mutableListOf(Pair(0, 3), Pair(2, 5))
    for (p in ps) {
        val a = p.first
        val b = p.second
        println("hash($a, $b) = ${hash(a, b)}")
    }*/
    val q = jin.readLine().toInt()
    val out = StringBuilder()
    for (j in 1..q) {
        val tokenizer = StringTokenizer(jin.readLine())
        val l1 = tokenizer.nextToken().toInt()
        val l2 = tokenizer.nextToken().toInt()
        val length = tokenizer.nextToken().toInt()
        //out.appendln("$l1 $l2 $length:")
        var works = (sum1s[l1 + length - 1] - sum1s[l1 - 1]) == (sum1s[l2 + length - 1] - sum1s[l2 - 1])
        if (works) {
            works = hash(l1 - 1, l1 + length - 1) == hash(l2 - 1, l2 + length - 1)
        }
        out.appendln(if (works) "YES" else "NO")
    }
    print(out)
}