fun main() {
    repeat(readLine()!!.toInt()) {

        fun ask(i: Int): Int {
            println("? ${i + 1}")
            return readLine()!!.toInt() - 1
        }

        fun answer(p: IntArray) {
            println("! ${p.joinToString(" ") { (it + 1).toString() }}")
        }

        val n = readLine()!!.toInt()
        val p = IntArray(n) { -1 }

        val seen = BooleanArray(n)
        for (i in 0 until n) {
            if (seen[i]) continue
            val first = ask(i)
            val list = mutableListOf(first)
            while (true) {
                val x = ask(i)
                list.add(x)
                seen[x] = true
                if (x == first) break
            }
            for ((x, y) in list.zipWithNext()) {
                p[x] = y
            }
        }
        answer(p)
    }
}