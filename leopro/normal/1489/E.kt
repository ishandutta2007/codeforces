fun main() {
    var l = 2
    var r = 1
    val position = IntArray(200_000)
    repeat(readLine()!!.toInt()) {
        val (query, number) = readLine()!!.split(' ')
        val id = number.toInt() - 1
        if (query == "L") {
            position[id] = --l
        } else if (query == "R") {
            position[id] = ++r
        } else {
            println(minOf(position[id] - l, r - position[id]))
        }
    }
}