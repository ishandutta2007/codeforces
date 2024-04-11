fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val word = readLine()!!
        for (c in 'a'..'z') {
            if (c !in word) return@repeat println(c)
        }
        for (c1 in 'a'..'z') {
            for (c2 in 'a'..'z') {
                if (c1.toString() + c2.toString() !in word) return@repeat println(c1.toString() + c2.toString())
            }
        }
        for (c1 in 'a'..'z') {
            for (c2 in 'a'..'z') {
                for (c3 in 'a'..'z') {
                    val s = c1.toString() + c2.toString() + c3.toString()
                    if (s !in word) return@repeat println(s)
                }
            }
        }
    }
}