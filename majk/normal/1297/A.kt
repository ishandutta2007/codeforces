fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val x = readLine()!!.toInt()
        when {
            x < 1000 -> println(x)
            x < 999500 -> println("${(x+500)/1000}K")
            else -> println("${(x+500000)/1000000}M")
        }
    }
}