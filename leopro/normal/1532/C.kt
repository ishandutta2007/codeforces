fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        println(List(n) { 'a' + it % k }.joinToString(""))
    }
}