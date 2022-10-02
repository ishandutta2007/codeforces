/**
 * Created by majk on 16.6.16.
 */

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val p = (1..n).map({ readLine()!!.split(' ') })
    p.sortedBy { it -> it[1].toInt() }.forEach { it -> println(it[0]) }
}