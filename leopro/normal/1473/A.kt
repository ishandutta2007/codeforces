fun main() {
    repeat(readLine()!!.toInt()){
        val (n, d) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
        println(if (a.all { it <= d } || a[0] + a[1] <= d) "YES" else "NO")

    }
}