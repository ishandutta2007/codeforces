import java.util.Scanner

fun main() {
    val cin = Scanner(System.`in`)
    val t = cin.nextInt()
    for(te in 1..t) {
        val a = cin.nextInt()
        val b = cin.nextInt()
        print(a + b)
        print('\n')
    }
}