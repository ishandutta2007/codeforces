fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }


fun run() {
    val (n,k) = readInts()
    val p = readInts()
    val pref = IntArray(n+1)
    pref[0] = 0
    for(i in 0 until n) pref[i+1] = pref[i] + p[i]
    var ret = 0
    for(i in 0 until n) {
        val cnt = n-i
        val nfree = cnt/k
        val cur = pref[i+nfree]-pref[i]
        ret = maxOf(ret,cur)
    }
    println(ret)
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}