import java.io._
import java.util._
import java.util.StringTokenizer

import scala.util.Sorting

object Solution {

  class Pair(val first: Int, val second: Int) extends Comparable[Pair] {
      override def compareTo(p: Pair): Int = {
        if (first != p.first)
          return first - p.first
        return second - p.second
      }
  }

  def solve(in: FastScanner, out: PrintWriter): Unit = {
    val n = in.nextInt()
    val max = in.nextInt()
    val avg: Long = in.nextLong()
    val want: Long = avg * n
    var have: Long = 0
    val a = new Array[Pair](n)
    for (i <- 0 until n) {
      val curr = in.nextInt()
      val cost = in.nextInt()
      have += curr
      a(i) = new Pair(cost, max - curr)
    }
    Sorting.quickSort(a)
    var res: Long = 0
    if (have > want)
      have = want
    for (i <- 0 until n) {
      val add: Long = Math.min(want - have, a(i).second)
      have += add
      res += add * a(i).first
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