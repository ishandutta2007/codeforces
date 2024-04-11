/**
 * Created by majk on 16.6.16.
 */

fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
    if (x > a || y > a || x < 0 || y < 0)
        print(2)
    else if (x == a || y == a || x == 0 || y == 0)
        print(1)
    else
        print(0)
}