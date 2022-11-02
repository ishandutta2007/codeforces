import java.util.Scanner

object Solution {
    def main(args: Array[String]) = {
	val in = new Scanner(System.in)
	val n = in.nextLong()
	println(if (n % 2 == 0) n / 2 else -((n + 1) / 2))
    }
}