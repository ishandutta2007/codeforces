import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T > 0) {
            val n = scanner.nextInt()
            val k = scanner.nextInt()
            val s = scanner.next()
            var d = 0
            var c = 0
            for (i in 0 until n) {
                if (s[i] == '(') d++ else {
                    if (--d == 0) {
                        c++
                    }
                }
            }
            println(Integer.min(c + k, n / 2))
            T--
        }
    }