fun main() {
    repeat(readLine()!!.toInt()) {
        val (l, r, a) = readLine()!!.split(' ').map { it.toInt() }
        var f = r / a + r % a
        val z = r / a * a
        if (z - 1 in l..r) f = maxOf(f, (z - 1) / a + (z - 1) % a)
        println(f)
    }
}