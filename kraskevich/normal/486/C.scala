import java.io._
import java.util.StringTokenizer

object Solution {
    val INF = 1000 * 1000 * 1000

    def solve(in: FastScanner, out: PrintWriter): Unit = {
        val n = in.nextInt()
        var pos = in.nextInt() - 1
        val a = in.next().toCharArray()
        var rep = 0
        var res = INF
        for (rep <- 0 until 2) {
            var i = 0
            val delta = new Array[Int](n)
            for (i <- 0 until n / 2) {
                val diff = (a(i) - a(n - i - 1) + 26) % 26
                delta(i) = Math.min(diff, 26 - diff)
            }
            var leftPos = n / 2 + 1
            var rightPos = -1
            var cur = 0
            for (i <- 0 until n / 2) {
                cur += delta(i)
                if (delta(i) > 0) {
                    leftPos = Math.min(leftPos, i)
                    rightPos = Math.max(rightPos, i)
                }
            }
            if (cur != 0) {
                cur += rightPos - leftPos
                if (leftPos <= pos && pos <= rightPos)
                    cur += Math.min(pos - leftPos, rightPos - pos)
                else if (pos < leftPos)
                    cur += leftPos - pos
                else
                    cur += pos - rightPos
            }
            res = Math.min(res, cur)
            pos = n - 1 - pos
            for (i <- 0 until n / 2) {
                val t = a(i)
                a(i) = a(n - i - 1)
                a(n - i - 1) = t
            }
        }
        out.println(res)
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