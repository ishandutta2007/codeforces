object Solution {
  def main(args: Array[String]) {
    val tokens = readLine().split(" ").map(_.toInt)
    val grownups = tokens(0)
    val kids = tokens(1)
    if (grownups == 0 && kids > 0) {
      println("Impossible")
    } else {
      printf("%d %d\n",
             grownups + (0 max (kids-grownups)),
             grownups + (0 max (kids-1)))
    }
  }
}