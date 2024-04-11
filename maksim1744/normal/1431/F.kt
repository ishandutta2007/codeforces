/*
    author:  Maksim1744
    created: 12.11.2020 18:39:15
*/

fun main() {
    var (n, k, x) = readLine()!!.split(" ").map{ it.toLong() }
    var a = readLine()!!.split(" ").map{ it.toLong() }
    var l: Long = -1;
    var r: Long = 1000000000.toLong() * 1000000000.toLong()
    while (r - l > 1) {
        var c = (l + r) / 2;
        var ind = 0.toLong()
        var needd = 0
        while (ind < n) {
            // println("$c, $ind")
            var ss = sortedSetOf(0.toLong())
            ss.remove(0.toLong())
            var sm: Long = 0
            for (i in ind until ind + x) {
                if (i == n) {
                    break;
                }
                ss.add(a[i.toInt()] * n + i)
                sm += a[i.toInt()]
            }
            ind = ind + x
            // if (c == 12.toLong()) {
            //     println("$c, $ind, $sm")
            // }
            if (ind > n) {
                ind = n;
            }
            while (sm > c) {
                var xx = ss.pollLast()
                sm -= xx / n
                ss.remove(xx)
                needd += 1
                if (ind < n) {
                    ss.add(a[ind.toInt()] * n + ind)
                    sm += a[ind.toInt()]
                    ind += 1
                }
            }
        }
        if (needd <= k) {
            r = c;
        } else {
            l = c;
        }
    }
    println(r)
}