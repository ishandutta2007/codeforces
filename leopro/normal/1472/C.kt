fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val maxResult = IntArray(n)
        for (i in a.indices.reversed()){
            maxResult[i] = a[i] + if (i + a[i] >= n) 0 else  maxResult[i + a[i]]
        }
        println(maxResult.maxOrNull())
    }
}