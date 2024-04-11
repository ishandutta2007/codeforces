fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() - 1 }.toMutableList()
        val ans = IntArray(n)
        for (i in a.indices.reversed()) {
            while (a[i] != i) {
                ans[i]++
                val x = a[0]
                a.removeAt(0)
                a.add(i, x)
            }
        }
        println(ans.joinToString(" "))
    }
}

data class Point(val x: Int, val w: Int)