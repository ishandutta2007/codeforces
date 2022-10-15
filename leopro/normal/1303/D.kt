import java.lang.Integer.min

fun main() {
    for (test in 0 until readLine()!!.toInt()) {
        val (m, _) = readLine()!!.split(' ').map { it.toLong() }
        val a = readLine()!!.split(' ').map { it.toLong() }.toLongArray()
        if (a.sum() < m) {
            println(-1)
            continue
        }
        val boxes = (0..64).map { exp -> a.count { it == (1L shl exp) } }.toIntArray()
        val bag = (0..64).map { (m shr it).toInt() and 1 }.toIntArray()
        var ans = 0
        for (i in 0 until 64) {
            while (bag[i] > 0) {
                val diff = min(boxes[i], bag[i])
                boxes[i] -= diff
                bag[i] -= diff
                if (bag[i] == 0) break
                for (j in i until 64) {
                    if (boxes[j] > 0) {
                        boxes[j] -= 1
                        boxes[j - 1] += 2
                        ans++
                        break
                    }
                }
            }
            boxes[i + 1] += boxes[i] / 2
        }
        println(ans)
    }
}