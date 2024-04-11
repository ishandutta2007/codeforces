import java.util.Scanner
  internal var s = Scanner(System.`in`)
  internal fun solve() {
    val str:String
    str = s.next()
    var res = 0
    var len = 0
    for (i in 0 until str.length)
    {
      val ch = str.get(i)
      if (ch == 'w')
      {
        res++
        res += len / 2
        len = 0
      }
      else
      {
        len++
      }
    }
    res += len / 2
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