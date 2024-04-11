import java.util.*
import kotlin.jvm.JvmStatic

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        var T = scanner.nextInt()
        while (T > 0) {
            var x: Long
            var y: Long
            x = scanner.nextInt().toLong()
            y = scanner.nextInt().toLong()
            var pp: Long = 1
            while (x * pp <= y) {
                pp *= 10
            }
            var ans: Long = 0
            while (pp >= 1) {
                val op = y / (x * pp)
                y -= op * x * pp
                ans += op
                pp /= 10
            }
            ans += y
            println(ans)
            T--
        }
    }