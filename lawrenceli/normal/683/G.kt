import java.util.Scanner
import java.util.Arrays

fun gcd(a: Long, b: Long): Long {
    if (b == 0L) return a
    else return gcd(b, a % b)
}

fun main(args: Array<String>) {
    var s = readLine()!!
    var sa = ""
    var sb = ""
    var f = false
    
    for (i in s.indices) {
        if (i >= 2) {
            if (f) {
                if (s[i] != ')') sb = sb.plus(s[i])
            } else {
                if (s[i] == '(') f = true
                else sa = sa.plus(s[i])
            }
        }
    }
    
    var a = if (sa == "") { 0L } else { sa.toLong() }
    var b = sb.toLong()
    
    var pwa = 1L
    var pwb = 1L
    
    for (i in 1..(sa.length)) pwa *= 10
    for (i in 1..(sb.length)) pwb *= 10
    
    var p = (a * (pwb - 1)) + b
    var q = pwa * (pwb - 1)
    var g = gcd(p, q)
    
    print(p / g)
    print('/')
    print(q / g)
}