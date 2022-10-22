import java.util.Scanner
  internal var scanner = Scanner(System.`in`)
  internal fun solve() {
    var n = scanner.nextInt()
    var a = IntArray(n)
    var used = BooleanArray(n)
    for (i in 0 until n)
    {
      a[i] = scanner.nextInt()
      used[i] = false
    }
    var lvl = 0
    for (i in 0 until n)
    {
      var minReq = 10000
      var ch = -1
      for (j in 0 until n)
      {
        if (used[j] == false)
        {
          if (minReq > a[j])
          {
            minReq = a[j]
            ch = j
          }
        }
      }
      if (lvl >= minReq)
      {
        used[ch] = true
        lvl = 0
        print(ch + 1)
        print(' ')
        lvl = 1
        continue
      }
      var maxReq = -10000
      ch = -1
      for (j in 0 until n)
      {
        if (used[j] == false)
        {
          if (maxReq < a[j])
          {
            maxReq = a[j]
            ch = j
          }
        }
      }
      used[ch] = true
      print(ch + 1)
      print(' ')
      lvl = lvl + 1
    }
    println("")
  }
  fun main(args:Array<String>) {
    // TODO Auto-generated method stub
    var T:Int
    T = scanner.nextInt()
    for (i in 0 until T)
    {
      solve()
    }
  }