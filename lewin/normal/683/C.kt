/**
 * Created by Lewin.gan on 6/16/2016.
 */
import java.util.*

fun main(args: Array<String>) {
    val a1 = readLine()!!.split(' ').map(String::toInt)
    val a2 = readLine()!!.split(' ').map(String::toInt)
    val b1 = a1.takeLast(a1.size-1)
    val b2 = a2.takeLast(a2.size-1)
    val c1 = (b1.subtract(b2)).plus(b2.subtract(b1))
    print(c1.size)
    for (x in c1) {
        print(" ")
        print(x)
    }
    println()

}