object Main {
  def main(args: Array[String]) = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    var a1 = 0
    var a0 = 0
    for (a <- 1 to n) {
        val x = sc.nextInt()
        if (x % 2 == 0) a0 = a0 + 1
        else a1 = a1 + 1
    }
    var x = math.min(a1,a0)
    a1 = a1 - x
    x = x + a1 / 3

    println(x)
  }
}