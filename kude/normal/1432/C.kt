import java.lang.Integer.sum

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!.split(" ").map{it.toInt()}.sum()
        println((s + n - 1) / n)
    }
}