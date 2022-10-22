fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, a, b) = readLine()!!.split(" ").map{it.toInt()}
        val s = StringBuilder(n)
        repeat(n) {
            s.append('a' + it % b)
        }
        println(s)
    }
}