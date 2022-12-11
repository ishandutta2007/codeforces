import scala.io.StdIn._
 
object A {

	def main(args: Array[String]) {
		val t = readInt()
		1 to t foreach { _ =>
			val n = readInt()
			for (i <- 1 to n) println(i)
		}
	}
}