import java.io._
import java.util._
import java.util.StringTokenizer

object Solution {
  def solve(in: FastScanner, out: PrintWriter): Unit = {
    val n = in.nextInt()
    val l = in.nextInt()
    val a = new Array[Int](n)
    for (i <- 0 until n)
      a(i) = in.nextInt()
    Arrays.sort(a)
    var res: Double = Math.max(a(0), l - a(n - 1))
    for (i <- 1 until n)
      res = Math.max(res, (a(i) - a(i - 1)) / 2.0)
    println(res)
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