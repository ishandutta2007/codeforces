/**
 * Created by majk on 16.6.16.
 */

fun main(args: Array<String>) {
    val a = readLine()!!.split(' ').map(String::toInt).drop(1).toSet();
    val b = readLine()!!.split(' ').map(String::toInt).drop(1).toSet();

    val c = a.union(b).minus(a.intersect(b));
    print(c.size)
    print(' ')
    print(c.map(Int::toString).joinToString(" "))
}