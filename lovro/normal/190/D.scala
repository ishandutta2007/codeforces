import scala.collection.mutable._

object Solution {
  def solve(arr: Array[Int], k: Int): Long = {
    val map = new HashMap[Int, ArrayBuffer[Int]]()
    for (i <- 0 until arr.length) {
      map.getOrElseUpdate(arr(i), new ArrayBuffer[Int]).append(i)
    }

    var minRight = Array.fill(arr.length)(arr.length)
    for ((key, offsets) <- map) {
      for (i <- 0 to offsets.length-k) {
        minRight(offsets(i)) = offsets(i+k-1)
      }
    }

    minRight = minRight.scanRight(minRight.length)(_ min _)
    minRight.map(arr.length - _.toLong).sum
  }

  def main(args: Array[String]) {
    val k = readLine().split(" ")(1).toInt
    val arr = readLine().split(" ").map(_.toInt)
    println(solve(arr, k))
  }
}