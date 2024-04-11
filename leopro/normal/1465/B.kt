import java.math.BigInteger

fun main() {
    fun ok(n: BigInteger): Boolean {
        var c = n
        while (c > BigInteger.ZERO){
            val d = c % BigInteger.TEN
            if (d != BigInteger.ZERO && n % d != BigInteger.ZERO) return false
            c /= BigInteger.TEN
        }
        return true
    }
    repeat(readLine()!!.toInt()){
        var n = readLine()!!.toBigInteger()
        while (!ok(n)) n++
        println(n)
    }
}