fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()

        fun ask(a: Int, b: Int, c: Int): Int {
            println("? $a $b $c")
            assert(listOf(a, b, c).distinct().size == 3)
            assert(listOf(a, b, c).all { it in 1..n })
            return 1 - readLine()!!.toInt().also { if (it == -1) throw AssertionError() }
        }

        fun guess(i: List<Int>) {
            assert(i.distinct().size == i.size)
            assert(i.all { it in 1..n })
            println("! ${i.size} ${i.joinToString(" ")}")
        }

        var prev = -1
        val q = IntArray(n + 1)
        for (i in 1 until n step 3) {
            val cur = ask(i, i + 1, i + 2)
            q[i] = cur
            if (prev != -1 && cur != prev) {
                val l = ask(i - 2, i - 1, i)
                val r = ask(i - 1, i, i + 1)
                val d = listOf(prev, l, r, cur).zipWithNext().index(prev to cur)
                val isImpostor = BooleanArray(n + 1)
                isImpostor[i - 3 + d] = prev.toBoolean()
                isImpostor[i + d] = cur.toBoolean()
                val impostor = if (isImpostor[i + d]) i + d else i - 3 + d
                val crewMate = if (isImpostor[i + d]) i - 3 + d else i + d
                for (j in i - 3..n) {
                    if (j != impostor && j != crewMate) {
                        isImpostor[j] = ask(impostor, j, crewMate).toBoolean()
                    }
                }
                for (j in 1 until i - 3 step 3) {
                    if (q[j] == 1) {
                        val x = ask(j, j + 1, crewMate)
                        if (x == 1) {
                            isImpostor[j] = true
                            isImpostor[j + 1] = true
                            isImpostor[j + 2] = ask(crewMate, impostor, j + 2).toBoolean()
                        } else {
                            isImpostor[j + 2] = true
                            isImpostor[j] = ask(crewMate, impostor, j).toBoolean()
                            isImpostor[j + 1] = !isImpostor[j]
                        }
                    } else {
                        val x = ask(j, j + 1, impostor)
                        if (x == 0) {
                            isImpostor[j] = false
                            isImpostor[j + 1] = false
                            isImpostor[j + 2] = ask(crewMate, impostor, j + 2).toBoolean()
                        } else {
                            isImpostor[j + 2] = false
                            isImpostor[j] = ask(crewMate, impostor, j).toBoolean()
                            isImpostor[j + 1] = !isImpostor[j]
                        }
                    }
                }
                return@repeat guess(isImpostor.indices.filter { isImpostor[it] })
            } else {
                prev = cur
            }
        }
    }
}

fun Boolean.toInt() = if (this) 1 else 0
fun Int.toBoolean() = this != 0
fun assert(c: Boolean) = if (!c) throw AssertionError() else null
fun List<Pair<Int, Int>>.index(p: Pair<Int, Int>) = indices.find { this[it].first == p.first && this[it].second == p.second }!!