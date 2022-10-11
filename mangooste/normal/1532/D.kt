import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    val n:Int = scanner.nextInt()
    val a = IntArray(n){ 0 }
    for (i in 0..n - 1) {
        a[i] = scanner.nextInt();
    }
    a.sort()
    var answer = 0L
    for (i in 0..n - 1) {
        if (i % 2 == 1) {
            answer += a[i] - a[i - 1]
        }
    }
    println(answer)
}