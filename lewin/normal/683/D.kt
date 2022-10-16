/**
 * Created by Lewin.gan on 6/16/2016.
 */
import java.util.*

fun main(args: Array<String>) {
    val q: Int = readLine()!!.toInt()
    for (t in 1..q) {
        val (n,m,p) = readLine()!!.split(' ').map(String::toInt)
        var ans = "No"
        for (i in 1..n) {
            if (p % i == 0 && p / i <= m) {
                ans = "Yes"
            }
        }
        println(ans)
    }
}