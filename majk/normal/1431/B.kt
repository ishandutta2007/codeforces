fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val S = readLine()!!
        println(S.count { it == 'w' } + S.split("w").map { it.length / 2 }.sum())
    }
}