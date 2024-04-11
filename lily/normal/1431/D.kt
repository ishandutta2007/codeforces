import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T: Int
        T = scanner.nextInt()
        while (T-- > 0) {
            var n: Int
            n = scanner.nextInt()
            val a = IntArray(n + 1)
            for (i in 1..n) {
                a[i] = scanner.nextInt() * 1000 + i
            }
            Arrays.sort(a, 1, n + 1)
            var i = 1
            var j = n
            val b = IntArray(n + 1)
            var bc = 0
            var flag = 0
            while (i <= j) {
                var cur = a[i] / 1000 - flag
                while (i <= j && cur > 0) {
                    b[bc++] = a[j--] % 1000
                    cur--
                }
                if (i <= j) {
                    b[bc++] = a[i++] % 1000
                }
                flag = 1
            }
            i = 0
            while (i < n) {
                System.out.printf("%d%c", b[i], if (i == n - 1) '\n' else ' ')
                i++
            }
        }
    }