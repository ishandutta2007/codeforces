
import java.util.*
  internal var s = Scanner(System.`in`)
  internal var n:Int = 0
  internal var a = LongArray(1)
  internal var res:Long = 0
  internal var v:Long = 0
  internal fun solve() {
    n = s.nextInt()
    a = LongArray(n)
    for (i in 0 until n)
    {
      a[i] = s.nextLong()
    }
    Arrays.sort(a)
    res = 0
    for (i in n - 1 downTo 0)
    {
      v = a[i] * (n - i)
      if (v > res) res = v
    }
    println(res)
  }
  fun main(args:Array<String>) {
    // TODO Auto-generated method stub
    val T = s.nextInt()
    for (i in 0 until T)
    {
      solve()
    }
  }