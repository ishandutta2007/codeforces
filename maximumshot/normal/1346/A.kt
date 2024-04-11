fun solveA() {
    var (n, k) = readLine()!!.split(" ").map { x -> x.toLong() }
    var n1: Long = 0
    var bl: Long = 0
    var br = n + 1
    var bm: Long = 0
    while (br - bl > 1) {
        bm = (bl + br) / 2
        if (bm + bm * k + bm * k * k + bm * k * k * k <= n)
            bl = bm
        else
            br = bm
    }
    n1 = bl
    println("${n1} ${n1 * k} ${n1 * k * k} ${n1 * k * k * k}")
}

fun main() {
    val tt = readLine()!!.toInt()
    for (ti in 0 until tt) {
        solveA()
    }
}