fun main() {
    val n = readLine()!!.toInt()
    val pos = query(1, n)
    if (query(1, pos) == pos){
        var l = 1
        var r = pos
        while (r - l > 1){
            val m = (l + r) / 2
            if (query(m, pos) == pos) l = m else r = m
        }
        guess(l)
    } else {
        var l = pos
        var r = n
        while (r - l > 1){
            val m = (l + r) / 2
            if (query(pos, m) == pos) r = m else l = m
        }
        guess(r)
    }
}

fun query(l: Int, r: Int): Int {
    if (l >= r) return -1
    println("? $l $r")
    return readLine()!!.toInt()
}

fun guess(i: Int){
    println("! $i")
}