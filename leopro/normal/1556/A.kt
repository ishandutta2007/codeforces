fun main() {
    repeat(readLine()!!.toInt()) {
        val (c, d) = readLine()!!.split(' ').map { it.toInt() }
        var ans = -1
        if ((c + d) % 2 == 0) {
            ans = if (c + d == 0 || c == d) {
                if (c == 0) 0 else 1
            } else 2
        }
        println(ans)
    }
}