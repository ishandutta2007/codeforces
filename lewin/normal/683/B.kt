/**
 * Created by Lewin.gan on 6/16/2016.
 */
import java.util.*

class RR(a: String, b: Int) {
    val x: String = a
    val y: Int = b
}

fun main(args: Array<String>) {
    val (n) = readLine()!!.split(' ').map(String::toInt)
    val arr = arrayListOf<RR>()
    for(i in 1..n) {
        val (x,y) = readLine()!!.split(' ')
        val z = y.toInt()
        val r = RR(x,z)
        arr.add(r)
    }
    Collections.sort(arr, object: Comparator<RR> {
        override fun compare(x: RR, y: RR) = x.y - y.y
    })
    for(m in arr) {
        println(m.x)
    }
}