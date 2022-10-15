fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val bottom = readLine()!!.split(' ').map { it.toInt() }
        val left = readLine()!!.split(' ').map { it.toInt() }
        val amount = IntArray(200)
        bottom.forEach { amount[it]++ }
        left.forEach { amount[it]++ }
        println(amount.count { it == 2 })
    }
}