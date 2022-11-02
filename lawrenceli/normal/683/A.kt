import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val(a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if ((0 < x) and (x < a) and (0 < y) and (y < a)) {
        println(0)
    } else if ((0 > x) or (x > a) or (0 > y) or (y > a)) {
        println(2)
    } else {
        println(1)
    }
}