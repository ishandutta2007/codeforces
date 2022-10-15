val primes = mutableListOf<Int>()

fun main() {
    for (p in 2 until 1e5.toInt()){
        var prime = true
        for (d in primes){
            if (p % d == 0) {
                prime = false
                break
            }
            if (d * d > p) break
        }
        if (prime) primes.add(p)
    }
    repeat(readLine()!!.toInt()) {
        val d = readLine()!!.toInt()
        val p = d.toLong().nextProbablePrime()
        val q = (p + d - 1L).nextProbablePrime()
        println(minOf(p * q, p * p * p))
    }
}

fun Long.nextProbablePrime() : Long{
    return primes.upperBound(this)
}

fun MutableList<Int>.upperBound(x: Long) : Long{
    var l = -1
    var r = size
    while (r - l > 1){
        val m = (l + r) / 2
        if (this[m] > x) r = m else l = m
    }
    return this[r].toLong()
}