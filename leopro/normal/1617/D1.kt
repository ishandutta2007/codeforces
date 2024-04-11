fun main() {
    repeat(readLine()!!.toInt()) {
        fun ask(a: Int, b: Int, c: Int): Int {
            println("? $a $b $c")
            return readLine()!!.toInt()
        }

        fun guess(i: List<Int>) {
            println("! ${i.size} ${i.joinToString(" ")}")
        }

        val n = readLine()!!.toInt()
        var prev = -1
        for (i in 3..n) {
            val cur = ask(i - 2, i - 1, i)
            if (prev != -1 && cur != prev) {
                val a = i - 2
                val b = i - 1
                val impostors = mutableListOf<Int>()
                val isImpostor = BooleanArray(n + 1)
                for (j in 1..n) {
                    if (j == a || j == b) continue
                    if (ask(a, b, j) == 0) impostors.add(j).also { isImpostor[j] = true }
                }
                var c = -1
                var i = -1
                for (j in 1..n) {
                    if (j == a || j == b) continue
                    if (isImpostor[j]) i = j else c = j
                }
                if (ask(c, i, a) == 0) impostors.add(a)
                if (ask(c, i, b) == 0) impostors.add(b)
                return@repeat guess(impostors)
            } else {
                prev = cur
            }
        }
    }
}