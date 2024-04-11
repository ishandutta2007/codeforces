/**
 * Created by majk on 16.6.16.
 */

fun gcd(a:Long,b:Long):Long {
    if (a<b) return gcd(b,a)
    if (b==0L) return a
    return gcd(b,a%b)
}


fun main(args: Array<String>) {
    val s = readLine()!!
    val pl = s.length - s.indexOf('(') - 2
    val sw = s.filterNot { it in ".()" }
    val n = sw.toLong()
    var pow : Long = 1
    var mpow : Long = 1
    (1..s.indexOf('(') - 2).forEach{ mpow *= 10 }
    (1..pl).forEach { pow *= 10 }
    val prep = n / pow
    val den = mpow*(pow - 1)
    val num = n % pow + prep * (pow-1)
    val g = gcd(num,den)


    print(num/g)
    print("/")
    print(den/g)




}