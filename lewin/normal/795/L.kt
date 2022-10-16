import java.util.Scanner;
object programkt {
  @JvmStatic fun main(args:Array<String>) {
    val `in` = Scanner(System.`in`)
    val n = `in`.nextInt()
    var k = `in`.nextInt()
    k -= 1
    val c = `in`.next().toCharArray()
    val freeb = IntArray(n)
    for (i in 0..n - 1)
    {
      if (c[i] == '0')
      freeb[i] = i
      else
      freeb[i] = freeb[i - 1]
    }
    var lo = 0
    var hi = n - 2
    while (lo < hi)
    {
      val mid = (lo + hi) / 2
      var last = 0
      for (j in 0..k - 1)
      {
        last = freeb[Math.min(n - 1, last + mid + 1)]
      }
      if (last == n - 1)
      hi = mid
      else
      lo = mid + 1
    }
    println(lo)
  }
}