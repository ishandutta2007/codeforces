import java.util.Scanner

object Solution {
    def countPairs(n: Long): Long = n * (n - 1) / 2
    
    def main(args: Array[String]) = {
	val in = new Scanner(System.in)
	val people = in.nextLong()
	val teams = in.nextLong()
	val max = countPairs(people - teams + 1)
	val size = people / teams
	val bigCount = people - size * teams 
	val smallCount = teams - bigCount
	val min = countPairs(size + 1) * bigCount + countPairs(size) * smallCount
	println(min + " " + max)
    }
}