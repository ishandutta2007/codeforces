import java.io._
import java.util._
import java.util.StringTokenizer

import scala.util.Sorting

object Solution {
  val INF: Long = 1e18.toLong;
  var x: Long = 0
  var y: Long = 0

  def countHits(num: Long): Long = num / y + num / x

  def solve(in: FastScanner, out: PrintWriter): Unit = {
    val n = in.nextInt()
    x = in.nextLong()
    y = in.nextLong()
    for (i <- 0 until n) {
      val a: Long = in.nextLong()
      var low: Long = 0
      var high: Long = INF
      while (high - low > 1) {
        val mid: Long = (low + high) / 2
        if (countHits(mid) >= a)
          high = mid
        else
          low = mid
      }
      if (high % y == 0 && high % x == 0)
        out.println("Both")
      else if (high % y == 0)
        out.println("Vanya")
      else
        out.println("Vova")
    }
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