fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!
        val c = readLine()!![0]
        if (s.length % 2 == 0) return println("NO")
        println(if (s.slice(0 until s.length step 2).any { it == c }) "YES" else "NO")
    }
}