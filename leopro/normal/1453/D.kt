fun main() {
    repeat(readLine()!!.toInt()) {
        val t = readLine()!!.toLong()
        if (t % 2 == 1L) return@repeat println(-1)
        val bits = (1 until 63).filter { bit -> t and (1L shl bit) != 0L }.map { it - 2 }
        val stages = mutableListOf<Int>()
        for (bit in bits) {
            if (bit == -1) continue
            stages.add(1)
            repeat(bit) { stages.add(0) }
        }
        repeat(bits.size) { stages.add(1) }
        println(stages.size)
        println(stages.joinToString(" "))
    }
}