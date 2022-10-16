/**
 * Created by Lewin.gan on 6/16/2016.
 */
import java.util.*

fun main(args: Array<String>) {
    val n: Int = readLine()!!.toInt()
    val r = readLine()!!.split(' ').map(String::toInt)
    val ans = ArrayList<Int>()
    for (i in 1..n) {
        ans.add(-1)
    }
    for (i in 1..n) {
        var amt = r[i-1]
        for (j in 1..n) {
            if (amt == 0 && ans[j-1] == -1) {
                ans[j-1] = i
                break
            }
            if (ans[j-1] == -1) amt -= 1
        }
    }
    print(ans[0])
    for (i in 1..n-1) {
        print(" ")
        print(ans[i])
    }
    println()
}