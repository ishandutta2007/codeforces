/**
 * Created by Lewin.gan on 6/16/2016.
 */

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)

fun main(args: Array<String>) {
    val s = readLine()!!.split("(")
    var a1 = s[0].substring(2)
    var a2 = s[1].substring(0, s[1].length-1)
    var x = s[0].length-2
    var den = 1L
    for(i in 1..x) {
        den *= 10
    }
    var num = if (x == 0) 0 else a1.toLong()

    var x1 = a2.length
    var d2 = 1L
    for(i in 1..x1) {
        d2 *= 10
    }
    var n1 = a2.toLong()
    d2 -= 1
    d2 *= den

    var g1 = gcd(num,den)
    num /= g1
    den /= g1
    var g2 = gcd(n1,d2)
    n1 /= g2
    d2 /= g2

    num = num*d2 + n1*den
    den = den * d2
    g1 = gcd(num, den)
    num /= g1
    den /= g1

    print(num)
    print("/")
    print(den)

}