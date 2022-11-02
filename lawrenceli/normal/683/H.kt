import java.util.Scanner
import java.util.Arrays

fun conv(a : IntArray) : IntArray {
    var ret = IntArray(a.size)
    for (i in a.indices) {
        ret[a[i]] = i
    }
    return ret
}

fun go(a : IntArray, b : IntArray) : IntArray {
    var ret = IntArray(a.size)
    for (i in a.indices) {
        ret[b[i]] = a[i]
    }
    return ret
}

fun exp(b: IntArray, e: Long) : IntArray {
    if (e == 0L) return IntArray(b.size, {i -> i})
    else {
        if (e % 2 == 1L) {
            var a = exp(b, e - 1)
            return go(a, b)
        } else {
            var a = exp(b, e / 2)
            return go(a, conv(a))
        }
    }
}

fun main(args: Array<String>) {
    var (n, k) = readLine()!!.split(' ').map(String::toLong)
    var x = readLine()!!.split(' ').map(String::toInt)
    var a = IntArray(x.size)
    for (i in x.indices) {
        a[i] = x[i] - 1
    }
    var b = exp(a, k)
    
    for (i in b) {
        print(i + 1)
        print(' ')
    }
}