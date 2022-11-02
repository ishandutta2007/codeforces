import java.util.Scanner

object Solution {
    def main(args: Array[String]) = {
        val in = new Scanner(System.in)
        var sum = 0
        var i = 0
        for (i <- 1 to 5)
            sum += in.nextInt()
        if (sum % 5 == 0 && sum > 0) 
            println(sum / 5)
        else
            println(-1)
    }
}