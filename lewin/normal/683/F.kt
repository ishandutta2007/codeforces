/**
 * Created by Lewin.gan on 6/16/2016.
 */
import java.util.*

fun main(args: Array<String>) {
    val s = readLine()!!.split('.')
    var first = true
    for (x in s) {
        if (!first) {
            print(".")
        }
        print(f(x, first))
        first = false
    }
    println()
}

fun f(s: String, ww: Boolean) : String {
    val p = s.split(",")
    var ret = ""
    var xx = true
    for(m in p) {
        if (!xx) {
            ret += ","
        }
        val r = m.split(" ")
        var first = true
        for (x in r) {
            var y = x.trim()
            if (y.length == 0) {
                continue
            }
            y = x.toLowerCase()
            if (first && xx) {
                y = y.capitalize()
            }
            if (!xx || !ww || !first) {
                ret += " "
            }
            xx = false
            first = false
            ret += y
        }
    }

    return ret
}