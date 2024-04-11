fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() - 1 }.toIntArray()
        if (a.slice(a.indices step 2).any { it % 2 == 1 }) return@repeat println(-1)
        val ans = mutableListOf<Int>()
        fun rotate(idx: Int) {
            for (i in 0 until idx / 2) {
                a[i] = a[idx - i].also { a[idx - i] = a[i] }
            }
            ans.add(idx + 1)
        }
        for (i in n - 1 downTo 2 step 2) {
            rotate(a.indexOf(i))
            rotate(a.indexOf(i - 1) - 1)
            rotate(a.indexOf(i - 1) + 1)
            rotate(2)
            rotate(i)
        }
        println(ans.size)
        println(ans.joinToString(" "))
    }
}