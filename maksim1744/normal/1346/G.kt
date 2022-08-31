/*
    author:  Maksim1744
    created: 26.10.2020 20:56:59
*/

const val N = 1000020
var anyp: Int = -1

fun gcd(a_: Int, b_: Int): Int {
    var a = a_
    var b = b_
    while (b != 0) {
        a %= b
        var c = a
        a = b
        b = c
    }
    return a
}

fun filterCamera(x: ArrayList<Int>, x1: Int, x2: Int): ArrayList<Int> {
    return ArrayList<Int>(x.filter{ it % (x2 - x1) != x2 % (x2 - x1) })
}

fun chechOneCamera(x: ArrayList<Int>, p: IntArray): Pair<Int, Int> {
    if (x.size == 0) {
        return Pair(1, anyp)
    }
    if (x.size == 1) {
        return Pair(x[0], anyp)
    }
    var d = x[1] - x[0];
    for (i in 0..x.size-2) {
        d = gcd(d, x[i + 1] - x[i])
    }
    if (p[d] == -1) {
        return Pair(-1, -1)
    }
    return Pair(x[0], p[d])
}

fun checkSet(x: ArrayList<Int>, x1: Int, x2: Int, p: IntArray): Pair<Pair<Int, Int>, Int> {
    var per0 = x2 - x1;
    for (per in 1..per0) {
        if (per0 % per == 0 && p[per] == per) {
            var res = chechOneCamera(filterCamera(x, x1, x1 + per), p);
            if (res.first != -1) {
                return Pair(res, per);
            }
        }
    }
    return Pair(Pair(-1, -1), -1)
}

fun main() {
    var (_, _) = readLine()!!.split(" ").map{ it.toInt() }
    var p = IntArray(N) {-1}
    var ps = readLine()!!.split(" ").map{ it.toInt() }
    for (i in ps) {
        anyp = i
        p[i] = i
        var j = i
        while (j < N) {
            if (p[j] == -1) {
                p[j] = i
            }
            j += i
        }
    }
    var x = ArrayList<Int>(readLine()!!.split(" ").map{ it.toInt() })

    if (x.size == 2) {
        println("YES")
        println("${x[0]} ${anyp}")
        println("${x[1]} ${anyp}")
        return
    }

    var res = checkSet(x, x[0], x[1], p)
    if (res.second != -1) {
        println("YES")
        println("${x[0]} ${res.second}")
        println("${res.first.first} ${res.first.second}")
        return
    }

    res = checkSet(x, x[0], x[2], p)
    if (res.second != -1) {
        println("YES")
        println("${x[0]} ${res.second}")
        println("${res.first.first} ${res.first.second}")
        return
    }

    res = checkSet(x, x[1], x[2], p)
    if (res.second != -1) {
        println("YES")
        println("${x[1]} ${res.second}")
        println("${res.first.first} ${res.first.second}")
        return
    }
    println("NO")
}