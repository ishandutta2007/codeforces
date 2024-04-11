fun main() {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    val a = IntArray(n)
    fun query(i: Int, j: Int): Int {
        println("or ${i + 1} ${j + 1}")
        println("and ${i + 1} ${j + 1}")
        val or = readLine()!!.toInt()
        val and = readLine()!!.toInt()
        return or + and
    }

    val sum01 = query(0, 1)
    val sum12 = query(1, 2)
    val sum02 = query(0, 2)
    a[0] = (sum01 + sum02 - sum12)  / 2
    a[1] = sum01 - a[0]
    a[2] = sum02 - a[0]
    for (i in 3 until n) {
        val s = query(0, i)
        a[i] = s - a[0]
    }
    println("finish ${a.sorted()[k - 1]}")
}

fun Boolean.toInt() = if (this) 1 else 0