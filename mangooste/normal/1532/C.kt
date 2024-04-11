import java.util.Scanner

fun main() {
    val s:String = "abcdefghijklmnopqrstuvwxyz"
    val scanner = Scanner(System.`in`)
    val t:Int = scanner.nextInt()
    repeat(t) {
        val n:Int = scanner.nextInt()
        val k:Int = scanner.nextInt()
        for (i in 0..n - 1) {
            print(s[i % k])
        }
        println()
    }
}