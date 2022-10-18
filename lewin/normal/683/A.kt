/**
 * Created by Lewin.gan on 6/16/2016.
 */
import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val (a,x,y) = readLine()!!.split(' ').map(String::toInt)
    val ans = if(x > 0 && x < a && y > 0 && y < a) {
        0
    } else if (x >= 0 && x <= a && y >= 0 && y <= a) {
        1
    } else {
        2
    }
    println(ans)
}