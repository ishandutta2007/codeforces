fun run() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map{it.toInt()}
    println(if (a.zipWithNext().any{(x,y) -> (y-x)%2==0}) "YES" else "NO")
}

fun main() {
    val ncase = readLine()!!.toInt()
    repeat(ncase) { run() }
}