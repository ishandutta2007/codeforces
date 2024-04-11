import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    val t:  Int = scanner.nextInt()
    repeat(t) {
        val a:Long = scanner.nextLong();
        val b:Long = scanner.nextLong();
        val k:Long = scanner.nextLong();
        println(a * ((k + 1) / 2) - b * (k / 2))
    }
}