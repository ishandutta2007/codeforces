import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T > 0) {
            val n = scanner.nextLong()
            val s = scanner.nextLong()
            var l: Long = 1
            var r = s
            while (l < r) {
                val mid = (l + r + 1) / 2
                var cur = mid
                var bu = s
                for (i in n downTo 1) {
                    if (cur == 1L) {
                        bu -= i
                        break
                    }
                    bu -= cur
                    cur = (cur + 1) / 2
                }
                if (bu >= 0) l = mid else r = mid - 1
            }
            println(l)
            T--
        }
    }