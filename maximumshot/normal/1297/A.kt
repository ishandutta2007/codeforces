import kotlin.math.roundToLong

fun main() {
    val n = readLine()!!.toInt()
    for (iter in 0 until n) {
        val s = readLine()!!.toLong()
        if (s < 1000)
            println(s)
        else {
            var x = (s / 1000.0).roundToLong()
            if (x < 1000)
                println("${x}K")
            else {
                x = (s / 1000000.0).roundToLong()
                println("${x}M")
            }
        }
    }
}