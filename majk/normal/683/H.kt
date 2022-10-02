/**
 * Created by majk on 16.6.16.
 */

fun main(args: Array<String>) {
    val (ns,ks) = readLine()!!.split(' ')
    val n = ns.toInt()
    val k = ks.toLong()
    val a = readLine()!!.split(' ').map(String::toInt)
    val l : Array<Int> = Array(n, {-1})
    val i : Array<Int> = Array(n, {-1})
    var c = 0
    var r = mutableListOf<MutableList<Int>>()
    (0..n-1).forEach {
        if (l[it] == -1) {
            var w = mutableListOf<Int>()
            var x = it
            var z = 0
            while (l[x] == -1) {
                l[x] = c
                i[x] = z++
                w.add(x)
                x = a[x]-1
            }
            ++c
            r.add(w)
        }
    }

    val ans = (0..n-1).map {
        val s = r[l[it]].size
        r[l[it]][(2 *s + i[it] - (k % s).toInt()) % s] + 1
    }
    println(ans.joinToString(" "))
}