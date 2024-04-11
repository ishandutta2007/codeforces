fun main() {
    var tt = readLine()!!.toInt()
    repeat(tt) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map{it.toLong()}.toLongArray()
        val b = readLine()!!.split(" ").map{it.toLong()}.toLongArray()
        val aoi = a.indices.sortedBy{a[it]}
        val boi = b.indices.sortedBy{b[it]}
        // a in [0, i) lose, while [i, n) win
        var mx: Long = -1
        var ans = Array<Int>(n){it}
        for(i in 0..n) {
            var t: Long = 1002003004005006007
            val na = Array<Int>(n){it}
            for(j in 0 until i) {
                val ja = aoi[j]
                val jb = boi[n-i+j]
                val tt = b[jb] - a[ja]
                if (tt < t) t = tt
                na[ja] = jb
            }
            for(j in i until n) {
                val ja = aoi[j]
                val jb = boi[j-i]
                val tt = a[ja] - b[jb]
                if (tt < t) t = tt
                na[ja] = jb
            }
            if (t > mx) {
                mx = t
                ans = na
            }
        }
        for(i in ans.indices) print("${ans[i]+1} ")
        println()
    }
}