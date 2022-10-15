fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val count = IntArray(26)
        fun switch(c: Char) = run { count[c - 'a'] = count[c - 'a'] xor 1 }
        repeat(2 * n + 1) {
            for (c in readLine()!!) switch(c)
        }
        println('a' + count.indexOf(1))
    }
}