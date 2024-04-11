fun main() {
    println("? ${(1..100).joinToString(" ")}")
    println("? ${(1..100).map { it shl 7 }.joinToString(" ")}")
    val x = readLine()!!.toInt()
    val y = readLine()!!.toInt()
    println("! ${(x and 127.inv()) + (y and (127 shl 7).inv())}")
}