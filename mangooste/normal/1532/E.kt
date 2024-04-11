import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    var n = scanner.nextInt()
    var a = ArrayList<Int>()
    repeat(n) {
        a.add(scanner.nextInt())
    }
    var sum = 0L
    for (i in 0..n - 1) {
        sum += a.get(i)
    }
    var b = ArrayList<Int>()
    for (i in a) {
        b.add(i)
    }
    b.sort()
    var answer = ArrayList<Int>()
    for (i in 0..n - 1) {
        var max = b.get(n - 1)
        if (max == a.get(i)) {
            max = b.get(n - 2)
        }
        if (2L * max == sum - a[i]) {
            answer.add(i + 1);
        }
    }
    println(answer.size)
    for (i in answer) {
        print(i)
        print(" ")
    }
    println()
}