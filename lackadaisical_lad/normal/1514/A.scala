object Solver {
  import InOut._
  def main(args: Array[String]): Unit = {
    for (_ <- 1 to nextInt) {
      val n = nextInt
      val arr = nextInts(n)
      var ans = "NO"
      for (num <- arr) {
        val rt = Math.round(Math.sqrt(num))
        if (rt * rt != num)
          ans = "YES"
      }
      out.println(ans)
    }
    out.flush()
  }
}

final object InOut {
    val in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in))
    val out = new java.io.PrintWriter(System.out, false)
    private[this] var tokenizer: java.util.StringTokenizer = _
    def nextToken: String = {
      while (tokenizer == null || !tokenizer.hasMoreTokens)
        tokenizer = new java.util.StringTokenizer(in.readLine)
      tokenizer.nextToken
    }
    def nextInt = Integer.parseInt(nextToken)
    def nextLong = java.lang.Long.parseLong(nextToken)
    def nextBig = BigInt(nextToken)
    def nextInts(n: Int) = Array.fill(n) { nextInt }
    def nextLongs(n: Int) = Array.fill(n) { nextLong }
    def nextBigs(n: Int) = Array.fill(n) { nextBig }
    def nextLine = in.readLine
}