fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val N = readLine()!!.toInt()
        val C = (0 until N).map { readLine()!!.split(' ').map { it.toInt() } }
        fun test(x: Int): Boolean {
            return C.count { it[0] <= x && it[1] >= x } == 1
        }

        var res = -1
        for (c in C) {
            if (test(c[0])) res = c[0]
            if (test(c[1])) res = c[1]
            if (test(c[1]+1)) res = c[1]+1
            if (test(c[0]-1)) res = c[0]-1
        }
        println(res)
    }
}