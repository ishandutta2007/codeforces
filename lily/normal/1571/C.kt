import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T-- > 0) {
            var a: String
            var b: String
            val n = scanner.nextInt()
            var lower = 0
            var upper = 1e9.toInt()
            for (i in 0 until n) {
                a = scanner.next()
                b = scanner.next()
                val should = scanner.nextInt()
                var k = 0
                while (k < a.length && k < b.length && a[a.length - k - 1] == b[b.length - k - 1]) {
                    k++
                }
                if (should == 1) upper = Integer.min(upper, k) else lower = Integer.max(lower, k + 1)
            }
            if (lower <= upper) {
                System.out.printf("%d\n", upper - lower + 1)
                for (i in lower..upper) {
                    System.out.printf("%d%c", i, if (i == upper) '\n' else ' ')
                }
            } else println("0\n")
        }
    }