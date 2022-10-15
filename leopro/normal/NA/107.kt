fun main() {
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toLong()
        println(if (n == n.takeHighestOneBit()) "NO" else "YES")
    }
}