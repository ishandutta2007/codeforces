/**
 * Created by majk on 16.6.16.
 */


fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt)
    var r : MutableList<Int> = mutableListOf()
    for (i in 1..n) {
        val q = a.indexOfFirst{it==0}
        r.add(q+1)
        a = a.slice(0..q).map{it-1} + a.slice(q+1..n-1)
    }
    print(r.joinToString(" "))
}