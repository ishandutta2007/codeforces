fun main() {
    val a=readLine()!!.split(" ").map({it.toInt()}).sorted()
    println("${a[3]-a[0]} ${a[3]-a[1]} ${a[3]-a[2]}")
}