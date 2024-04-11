import java.io._
import java.util._
import java.util.StringTokenizer

import scala.util.Sorting

object Solution {
  def gcd(a: Long, b: Long): (Long, Long) = {
    if (a == 0)
      return (0, 1)
    if (b == 0)
      return (1, 0)
    val t = gcd(b % a, a)
    val x = t._2 - (b / a) * t._1
    val y = t._1
    return (x, y)
  }

  def getInv(x: Long, mod: Long): Long = {
    val t = gcd(x, mod)
    return t._1
  }

  def solve(in: FastScanner, out: PrintWriter): Unit = {
    val n = in.nextInt()
    val m = in.nextInt()
    val dx = in.nextInt()
    val dy = in.nextInt()
    val count = new Array[Int](n)
    for (i <- 0 until m) {
      val x = in.nextInt()
      val y = in.nextInt()
      val inv: Long = getInv(dx, n)
      val k: Long = (-x * inv % n + n) % n
      val startY: Int = ((y + k * dy) % n).toInt
      count(startY) += 1
    }
    var maxY = 0
    for (i <- 0 until n)
      if (count(i) > count(maxY))
        maxY = i
    out.println(0 + " " + maxY)
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