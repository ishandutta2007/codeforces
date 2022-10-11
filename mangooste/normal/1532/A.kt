import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    val t:  Int = scanner.nextInt()
    repeat(t) {
        val a:Int = scanner.nextInt()
        val b:Int = scanner.nextInt()
        println(a + b)
    }
}