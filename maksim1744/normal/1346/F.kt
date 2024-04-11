/*
    author:  Maksim1744
    created: 26.10.2020 20:28:41
*/

fun main() {
    var (n, m, q) = readLine()!!.split(" ").map{ it.toInt() }
    var a = ArrayList<ArrayList<Long>>()
    for (i in 0 until n) {
        a.add(ArrayList<Long>(readLine()!!.split(" ").map{ it.toLong() }))
    }

    var rows = LongArray(n)
    var cols = LongArray(m)

    for (i in 0..n-1) {
        for (j in 0..m-1) {
            rows[i] += a[i][j]
            cols[j] += a[i][j]
        }
    }


    for (query in 0..q) {
        if (query != 0) {
            var (x, y, z) = readLine()!!.split(" ").map{ it.toInt() }
            --x
            --y
            var delta = z.toLong() - a[x][y]
            a[x][y] = z.toLong()
            rows[x] += delta
            cols[y] += delta
        }
        var rsum = LongArray(n)
        var csum = LongArray(m)
        var s: Long = 0
        var cnt: Long = 0
        for (i in 0..n-1) {
            rsum[i] += s
            cnt += rows[i]
            s += cnt
        }
        s = 0
        cnt = 0
        for (i in n-1 downTo 0) {
            rsum[i] += s
            cnt += rows[i]
            s += cnt
        }
        s = 0
        cnt = 0
        for (i in 0..m-1) {
            csum[i] += s
            cnt += cols[i]
            s += cnt
        }
        s = 0
        cnt = 0
        for (i in m-1 downTo 0) {
            csum[i] += s
            cnt += cols[i]
            s += cnt
        }
        print(rsum.minOrNull()!! + csum.minOrNull()!!)
        print(" ")
    }
    print("\n")
}