fun main() {
    val (n, m) = readLine()!!.split(' ').map { it.toInt() }

    fun query(c: BooleanArray): Int {
        println("? ${c.joinToString("") { if (it) "1" else "0" }}")
        return readLine()!!.toInt()
    }

    fun query(x: Int): Int {
        val c = BooleanArray(m)
        c[x] = true
        return query(c)
    }

    val l = IntArray(m)
    for (i in 0 until m) l[i] = query(i)
    val indices = (0 until m).sortedBy { l[it] }
    var cur = 0
    val c = BooleanArray(m)
    for (i in indices) {
        c[i] = true
        val new = query(c)
        if (new == cur + l[i]) {
            cur = new
        } else {
            c[i] = false
        }
    }
    println("! $cur")
}