fun run() {
    val (n,t) = readLine()!!.split(" ").map{it.toInt()}
    println((0 until n).map{
        readLine()!!.split(" ").map{it.toInt()}
    }.filter{ (l,r) -> l<=t&&t<=r}.map{ (l,r) -> r-t+1 }.maxOrNull()?:0)
}

fun main() {
    val ncase = readLine()!!.toInt()
    repeat(ncase) { run() }
}