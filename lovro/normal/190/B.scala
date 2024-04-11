object Solution {
  class Point(xin: Long, yin: Long) {
    val x = xin;
    val y = yin;
  }

  def sqr(x: Long): Long = x*x
  
  def sqrDist(p1: Point, p2: Point): Long = {
    return sqr(p1.x - p2.x) + sqr(p1.y - p2.y)
  }

  class Circle(centerin: Point, radiusin: Long) {
    val center = centerin;
    val radius = radiusin;

    def contains(p: Point): Boolean = sqrDist(p, center) <= sqr(radius)

    def intersects(other: Circle): Boolean = {
      sqr(radius) + 2*radius*other.radius + sqr(other.radius) >= sqrDist(center, other.center)
    }

    def contains(other: Circle): Boolean = {
      val d = math.sqrt(sqrDist(center, other.center))
      d + other.radius <= radius
    }
  }

  def readCircle(): Circle = {
    val tokens = readLine().split(" ").map(_.toInt)
    new Circle(new Point(tokens(0), tokens(1)), tokens(2))
  }

  def solve(c1: Circle, c2: Circle): Double = {
    val d = math.sqrt(sqrDist(c1.center, c2.center))
    if (c1 contains c2) {
      c1.radius - (d + c2.radius)
    } else if (c2 contains c1) {
      c2.radius - (d + c1.radius)
    } else if (c1 intersects c2) {
      0
    } else {
      d - (c1.radius + c2.radius)
    }
  }

  def main(args: Array[String]) {
    printf("%.12f\n", solve(readCircle(), readCircle()) / 2)
  }
}