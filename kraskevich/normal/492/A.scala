import java.io._
import java.util.StringTokenizer

object Solution {
  def solve(in: FastScanner, out: PrintWriter): Unit = {
    val n = in.nextInt()
    var res = 0
    var size = 1
    var sum = 0
    while (sum <= n) {
      sum += size
      res += 1
      size += res + 1
    }
    out.println(res - 1)
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