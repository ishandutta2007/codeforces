import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    val n = readInt()
    val c = readInts()
    val to = Array(20){Array<Int>(n){-1} }
    val s = Array(20){Array<Long>(n){0} }
    val st = java.util.Stack<Int>()
    for(i in 0 until n) {
        while(!st.empty() && c[st.peek()] <= c[i]) st.pop()
        if (!st.empty()) {
            val j = st.peek()
            to[0][i] = j
            s[0][i] = (i - j).toLong() * c[i].toLong()
        } else {
            s[0][i] = (i + 1).toLong() * c[i].toLong()
        }
        st.add(i)
    }
    //println(s[0].joinToString(" "))
    for(k in 0 until 19) {
        for(i in 0 until n) {
            val j = to[k][i]
            if (j != -1) {
                to[k+1][i] = to[k][j]
                s[k+1][i] = s[k][i] + s[k][j]
            }
        }
        //println(to[k+1].joinToString(" "))
        //println(s[k+1].joinToString(" "))
    }
    val q = readInt()
    val ansArr = Array<Long>(q){0}
    repeat(q) {
        var (l, r) = readInts()
        l -= 1
        // [l, r)
        var now = r - 1
        var ans: Long = 0
        var k = 19
        while(true) {
            //println("$ans, $k, $now")
            if (to[k][now] == -1 || to[k][now] < l) {
                if (k > 0) k--
                else {
                    ans += (now - l + 1).toLong() * c[now].toLong()
                    break
                }
            } else {
                ans += s[k][now]
                now = to[k][now]
            }
        }
        ansArr[it] = ans
    }
    println(ansArr.joinToString(" "))
}