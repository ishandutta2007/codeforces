fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val words = List(n) { readLine()!! }
        var ans = 0
        favourite@ for (max in 'a'..'e') {
            val processed = words.map { it.count { it == max } to it.count { it != max } }
                .sortedBy { it.second - it.first }
            var withMax = 0
            var withoutMax = 0
            for (i in 0 until n) {
                val (a, b) = processed[i]
                if (withMax + a <= withoutMax + b) {
                    ans = maxOf(ans, i)
                    continue@favourite
                }
                withMax += a
                withoutMax += b
            }
            ans = n
        }
        println(ans)
    }
}