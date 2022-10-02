/**
 * Created by majk on 16.6.16.
 */

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        val (n,m,p) = readLine()!!.split(' ').map(String::toInt)
        val res = (1..m).any { it -> p % it  == 0 && p / it <= n }
        if (res) println("Yes") else println("No")
    }
}