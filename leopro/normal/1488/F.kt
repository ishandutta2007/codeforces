fun main() {
    val n = readLine()!!.toInt()
    val c = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
    val q = readLine()!!.toInt()
    val queries = List(q) { readLine()!!.split(' ').map { it.toInt() }.run { first() - 1 to last() - 1 } }
    val lefts = Array(n) { mutableListOf<Pair<Int, Int>>() }
    for (i in queries.indices) lefts[queries[i].second].add(queries[i].first to i)
    val ans = LongArray(q)
    //<stack>
    val index = IntArray(n)
    val value = IntArray(n)
    val duration = IntArray(n)
    val prefixSum = LongArray(n + 1)
    var i = -1
    //</stack>
    for (rg in c.indices) {
        while (i >= 0 && value[i] <= c[rg]) --i
        ++i
        index[i] = if (i == 0) 0 else index[i - 1] + duration[i - 1]
        value[i] = c[rg]
        duration[i] = rg - index[i] + 1
        prefixSum[i + 1] = prefixSum[i] + value[i] * 1L * duration[i]
        for ((lf, j) in lefts[rg]){
            var l = 0
            var r = i + 1
            while (r - l > 1){
                val m = (l + r) / 2
                if (index[m] > lf) r = m else l = m
            }
            val sum = prefixSum[i + 1] - prefixSum[r] + value[l] * 1L * (index[l] + duration[l] - lf)
            ans[j] = sum
        }
    }
    println(ans.joinToString(" "))
}