import java.io._
import java.util.Arrays
import java.util.StringTokenizer

object Solution {
    val MOD = 1000 * 1000 * 1000 + 9
    val N = 100 * 1000 + 10

    class SegmentTree(val n : Int) {
        private val data = new Array[Int](4 * n + 10)
        private val ways = new Array[Int](4 * n + 10)
        Arrays.fill(ways, 1)

        def getMax(l: Int, r : Int): (Int, Int) = getMax(0, 0, n - 1, l, r)

        private def getMax(i: Int, tl: Int, tr: Int, l: Int, r: Int): (Int, Int) = {
            if (l == tl && r == tr)
                return (data(i), ways(i))
            var sl = 0
            var sr = 0
            var wl = 1
            var wr = 1
            val m = (tl + tr) / 2
            if (l <= m) {
                val t = getMax(2 * i + 1, tl, m, l, Math.min(r, m))
                sl = t._1
                wl = t._2
            }
            if (r > m) {
                val t = getMax(2 * i + 2, m + 1, tr, Math.max(m + 1, l), r)
                sr = t._1
                wr = t._2
            }
            if (sl == sr && sl != 0)
                (sl, (wl + wr) % MOD)
            else if (sl > sr)
                (sl, wl)
            else
                (sr, wr)
        }

        def put(pos: Int, value: Int, add: Int): Unit = put(0, 0, n - 1, pos, value, add)

        private def put(i: Int, tl: Int, tr: Int, pos: Int, value: Int, add: Int): Unit = {
            if (pos == tl && pos == tr) {
                if (data(i) == value)
                    ways(i) = (ways(i) + add) % MOD
                else if (data(i) < value) {
                    data(i) = value
                    ways(i) = add
                }
                return
            }
            val m = (tl + tr) / 2
            if (pos <= m)
                put(2 * i + 1, tl, m, pos, value, add)
            else
                put(2 * i + 2, m + 1, tr, pos, value, add)
            if (data(2 * i + 1) == data(2 * i + 2) && data(2 * i + 1) != 0) {
                data(i) = data(2 * i + 1)
                ways(i) = (ways(2 * i + 1) + ways(2 * i + 2)) % MOD
            } else if (data(2 * i + 1) > data(2 * i + 2)) {
                data(i) = data(2 * i + 1)
                ways(i) = ways(2 * i + 1)
            } else {
                data(i) = data(2 * i + 2)
                ways(i) = ways(2 * i + 2)
            }
        }
    }

    def solve(in: FastScanner, out: PrintWriter): Unit = {
        val n = in.nextInt()
        val a = new Array[Int](n)
        var i = 0
        for (i <- 0 until n)
            a(i) = in.nextInt()
        val equalLeft = new Array[Int](n)
        val equalRight = new Array[Int](n)
        val lessLeft = new Array[Int](n)
        val greaterRight = new Array[Int](n)
        val cntLess = new Array[Int](n)
        val treeLeft = new SegmentTree(N)
        for (i <- 0 until n) {
            equalLeft(i) = treeLeft.getMax(0, a(i))._1
            lessLeft(i) = treeLeft.getMax(0, a(i) - 1)._1
            cntLess(i) = treeLeft.getMax(0, a(i) - 1)._2
            treeLeft.put(a(i), lessLeft(i) + 1, cntLess(i))
        }
        val maxSeq = treeLeft.getMax(0, N - 1)
        val maxLen = maxSeq._1
        val cntTotal = maxSeq._2
        val treeRight = new SegmentTree(N)
        val res = new Array[Int](n)
        for (i <- 0 until n) {
            val j = n - i - 1
            equalRight(j) = treeRight.getMax(a(j), N - 1)._1
            greaterRight(j) = treeRight.getMax(a(j) + 1, N - 1)._1
            val cntGreater = treeRight.getMax(a(j) + 1, N - 1)._2
            treeRight.put(a(j), greaterRight(j) + 1, cntGreater)
            val any = lessLeft(j) + greaterRight(j) + 1 == maxLen
            if (!any) {
                res(j) = 1
            } else {
                if (cntLess(j) * 1L * cntGreater % MOD == cntTotal)
                    res(j) = 3
                else
                    res(j) = 2
            }
        }
        for (i <- 0 until n)
            out.print(res(i))
        out.println()
    }

    def main(args: Array[String]): Unit = {
        val in = new FastScanner(System.in)
        val out = new PrintWriter(System.out)
        solve(in, out)
        out.flush()
    }

    class FastScanner(val in: InputStream) {
        var st: StringTokenizer = null
        var br = new BufferedReader(new InputStreamReader(in))

        def next(): String = {
            while (st == null || !st.hasMoreTokens()) {
                val line = br.readLine()
                if (line == null)
                    throw new IOException()
                st = new StringTokenizer(line)
            }
            return st.nextToken()
        }

        def nextInt(): Int = Integer.parseInt(next())

        def nextLong(): Long = java.lang.Long.parseLong(next())

        def close(): Unit = {
            br.close()
        }
    }
}