fun main() {
    val n = readLine()!!.toInt()
    val input = List(2 * n - 2) { readLine()!! }
    var (i, j) = IntArray(input.size) { it }.filter { input[it].length == n - 1 }
    fun check(): Boolean {
        val usedPrefix = BooleanArray(n)
        val usedSuffix = BooleanArray(n)
        println(List(input.size) { idx ->
            val str = input[idx]
            if (str == input[i].slice(str.indices) && !usedPrefix[str.length]) {
                usedPrefix[str.length] = true
                'P'
            } else if (str == input[j].slice(input[j].length - str.length until input[j].length) && !usedSuffix[str.length]) {
                usedSuffix[str.length] = true
                'S'
            } else {
                return false
            }
        }.joinToString(""))
        return true
    }
    if (!check()) {
        i = j.also { j = i }
        check()
    }
}