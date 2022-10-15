import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T: Int
        T = scanner.nextInt()
        while (T-- > 0) {
            var a = String()
            a = scanner.next()
            var ans = 0
            var i = 0
            while (i < a.length) {
                if (a[i] == 'v' && i + 1 < a.length && a[i + 1] == 'v') {
                    ans++
                    i++
                } else if (a[i] == 'w') {
                    ans++
                }
                i++
            }
            println(ans)
        }
    }