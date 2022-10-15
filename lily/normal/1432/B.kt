import java.util.*

fun main() {
    var T: Int
    val scanner = Scanner(System.`in`)
    T = scanner.nextInt()
    while (T-- > 0) {
        var n = scanner.nextInt()
        if (n < 2) n = 2
        println((n - 1) / 2)
    }
}