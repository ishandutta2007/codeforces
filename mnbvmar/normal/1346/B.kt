import kotlin.math.*

fun main() {
    val t = readLine()!!.toInt()
    for (tid in 1..t) {
         val (n, k1, k2) = readLine()!!.split(' ').map(String::toInt)
         val days = readLine()!!
         var total = 0
         var last_day = 0
         for (c in days) {
            if (c == '0') {
                last_day = 0
            } else {
                last_day = min(k1, k2 - last_day)
            }
            total += last_day
         }
         println(total)
    }
}