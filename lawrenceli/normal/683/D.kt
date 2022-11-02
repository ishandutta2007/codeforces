import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    var (q) = readLine()!!.split(' ').map(String::toInt)
    for (i in 1..q) {
        var (n, m, p) = readLine()!!.split(' ').map(String::toInt)
        var good : Boolean = false
        for (i in 1..n) {
            if ((p % i == 0) and (p / i <= m)) {
                good = true
            }
        }
        
        if (good) {
            println("Yes")
        } else {
            println("No")
        }
    }
}