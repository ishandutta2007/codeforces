fun main() {
    val n = readLine()!!.toInt()
    val w = run {
        var l = 0
        var r = n * 2001
        while (r - l > 1) {
            val m = (l + r) / 2
            if (query(m) == 1) r = m else l = m
        }
        r
    }
    var min = w
    for (i in 1..n) {
        val h = query((w - 1) / i)
        if (h != 0) min = minOf(min.toLong(), h * 1L * ((w - 1) / i)).toInt()
    }
    println("! $min")
}

fun query(w: Int): Int {
    if (w == 0) return 0
    println("? $w")
    return readLine()!!.toInt()
}