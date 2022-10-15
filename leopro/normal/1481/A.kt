fun main() {
    repeat(readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(' ').map { it.toInt() }
        val cmd = readLine()!!
        val (u, d, l, r) = listOf('U', 'D', 'L', 'R').map { chr -> cmd.count { it == chr } }
        val hor = (x < 0 && l >= -x) || (x >= 0 && r >= x)
        val ver = (y < 0 && d >= -y) || (y >= 0 && u >= y)
        println(if (hor && ver) "YES" else "NO")
    }
}