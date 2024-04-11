fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    val A = readLine()!!.split(" ").map{ it.toLong() }
    val B = A.mapIndexed { i,a -> a * N + i - N + 1 }
    println(B.max())
}