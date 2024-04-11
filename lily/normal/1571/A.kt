import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T-- > 0) {
            val s = scanner.next()
            var lt = 0
            var gt = 0
            for (i in 0 until s.length) {
                if (s[i] == '<') {
                    lt = 1
                } else if (s[i] == '>') {
                    gt = 1
                }
            }
            val output = "=<>?"
            println(output[lt + gt * 2])
        }
    }