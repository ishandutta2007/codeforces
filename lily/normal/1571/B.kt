import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T-- > 0) {
            var n: Int
            var a: Int
            var va: Int
            var c: Int
            var vc: Int
            var b: Int
            n = scanner.nextInt()
            a = scanner.nextInt()
            va = scanner.nextInt()
            c = scanner.nextInt()
            vc = scanner.nextInt()
            b = scanner.nextInt()
            println(Integer.min(vc, va + b - a))
        }
    }