import java.util.Scanner
  internal var s = Scanner(System.`in`)
  internal fun solve() {
    val n:Int
    val k:Int
    n = s.nextInt()
    k = s.nextInt()
    val a = IntArray(n)
    for (i in 0 until n)
    {
      a[i] = s.nextInt()
    }
    var res = 0
    for (s in 1..n)
    {
      val fr = s / k
      var sum = 0
      for (j in n - s until n - s + fr)
      {
        sum += a[j]
      }
      if (sum > res) res = sum
    }
    println(res)
  }
  fun main(args:Array<String>) {
    // TODO Auto-generated method stub
    val T:Int
    T = s.nextInt()
    for (i in 0 until T)
    {
      solve()
    }
  }