fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

fun run() {
    val (n) = readInts()
    val a = readInts()
    val b = readInts()
    var bestshift = -1
    var bestdiff = -1
    for(shift in 0 until n) {
        var diff = Int.MAX_VALUE
        for(i in 0 until n) {
            val j = (i+shift)%n
            diff = minOf(diff, kotlin.math.abs(a[i]-b[j]))
        }
        if(diff > bestdiff) { bestshift = shift; bestdiff = diff }
    }
    //println("res $bestdiff $bestshift")
    println((0 until n).map{(it+bestshift)%n+1}.joinToString(" "))

}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}