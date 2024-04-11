fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val s = readLine()!!.map { it == '1' }.toMutableList()
        var i = 0
        while (s.any { it }){
            s.removeAt(i)
            if (s.isNotEmpty()) i = (i + k - 1) % s.size
        }
        println(n - s.size)
    }
}