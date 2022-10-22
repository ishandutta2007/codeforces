import java.util.Scanner
  internal var scanner = Scanner(System.`in`)
  internal fun solve() {
    var n = scanner.nextInt()
    var a = IntArray(n)
    var b = IntArray(n)
    var p = IntArray(n)
    var res:Int
    res = -1
    var bestp = IntArray(n)
    for (i in 0 until n)
    {
      a[i] = scanner.nextInt()
    }
    for (i in 0 until n)
    {
      b[i] = scanner.nextInt()
    }
    for (i in 0 until n)
    {
      p[i] = i
    }
    for (wtf in 0 until n)
    {
      var t = p[0]
      for (i in 0 until n - 1)
      {
        p[i] = p[i + 1]
      }
      p[n - 1] = t
      var ub = 10000000
      for (i in 0 until n)
      {
        var v:Int
        v = a[i] - b[p[i]]
        if (v < 0) v = -v
        if (v < ub) ub = v
      }
      if (ub > res)
      {
        res = ub
        for (i in 0 until n)
        {
          bestp[i] = p[i]
        }
      }
    }
    for (i in 0 until n)
    {
      print(bestp[i] + 1)
      print(" ")
    }
    println("")
  }
  fun main(args:Array<String>) {
    // TODO Auto-generated method stub
    var T = scanner.nextInt()
    for (i in 0 until T)
    {
      solve()
    }
  }