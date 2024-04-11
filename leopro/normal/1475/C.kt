fun main() {
    repeat(readLine()!!.toInt()){
        val (n, m, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() - 1 }.toIntArray()
        val b = readLine()!!.split(' ').map { it.toInt() - 1 }.toIntArray()
        val boyCnt = IntArray(n)
        val girlCnt = IntArray(m)
        for (boy in a) boyCnt[boy]++
        for (girl in b) girlCnt[girl]++
        var ans = 0L
        for (i in 0 until k){
            ans += k - boyCnt[a[i]] - girlCnt[b[i]] + 1
        }
        println(ans / 2)
    }
}