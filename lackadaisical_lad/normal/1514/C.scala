object Solver {
  import InOut._
  def main(args: Array[String]): Unit = {
    @annotation.tailrec
    def gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
    
    val n = nextInt
    val coprime = for (i <- 1 until n if gcd(i, n) == 1) yield i
    val prod = coprime.foldLeft(1: Long)(_ * _ % n)
    val ans = if (prod == 1) coprime else {
      val pos = coprime indexOf prod
      assert(pos != -1)
      coprime.take(pos) ++ coprime.takeRight(coprime.length - pos - 1)
    }
    out.println(ans length)
    out.println(ans mkString " ")
    out.flush
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