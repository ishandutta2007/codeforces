fun main() {
//    val firstWin = BooleanArray(200)
//    for (i in 2 until 200) {
//        for (d in 2 until i) {
//            if (i % d != 0) continue
//            if (!firstWin[i - d]) firstWin[i] = true
//        }
//        if (firstWin[i]) println("$i\tyes") else println("$i\tno")
//    }
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        if ((0 until 15).any { n == 2 shl (2 * it) }) return@repeat println("Bob")
        println(if (n % 2 == 0) "Alice" else "Bob")
    }
}