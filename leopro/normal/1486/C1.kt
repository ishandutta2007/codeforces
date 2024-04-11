fun main() {
    val n = readLine()!!.toInt()
    var l = 1
    var r = n
    var pos = query(l, r)
    while (r - l > 1) {
        val m = (l + r) / 2
        val inside = if (pos <= m) query(l, m) else query(m + 1, r)
        if (inside == pos) {
            if (pos <= m) r = m else l = m + 1
        } else {
            if (pos > m) r = m else l = m + 1
            if (l < r) pos = query(l, r)
        }
    }
    if (l == r) pos = l
    guess(l xor r xor pos)
}

fun query(l: Int, r: Int): Int {
    if (l >= r) return -1
    println("? $l $r")
    return readLine()!!.toInt()
}

fun guess(i: Int){
    println("! $i")
}