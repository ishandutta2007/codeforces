fun main() {
    val T = readLine()!!.toInt()
    repeat(T) {
        val N = readLine()!!.toInt()
        val A = readLine()!!.split(" ").map { it.toLong() }
        var B = A.mapIndexed { i, v -> v to i+1 }.sortedBy { it.first }
        val C = mutableListOf<Int>()
        var F = 0
        while (B.isNotEmpty()) {
            val s = B[0].first.toInt()
            if (B.size > s - F) {
                C.addAll(B.takeLast(s - F).map { it.second })
                C.add(B[0].second)
                B = B.subList(1, B.size - s + F)
            } else {
                C.addAll(B.map { it.second })
                B = listOf()
            }
            F = 1
        }
        println(C.joinToString(" ") { it.toString() })
    }
}