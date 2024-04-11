fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!.toList().sorted()
        val n = s.size
        val cnt = IntArray(26)
        for (c in s) cnt[c - 'a']++
        if (cnt.any { it == 1 }) {
            val smallestChar = 'a' + cnt.indices.find { cnt[it] == 1 }!!
            print(smallestChar)
            println(s.filter { it != smallestChar }.joinToString(""))
            return@repeat
        }
        if (cnt.count { it != 0 } == 1) return@repeat println(s.joinToString(""))

        val a = cnt.indices.find { cnt[it] != 0 }!!
        if (cnt[a] <= (n + 2) / 2) {
            val first = s.filter { it == 'a' + a }.drop(2)
            val other = s.filter { it != 'a' + a }
            val ans = MutableList(2) { 'a' + a }
            for (i in other.indices) {
                ans.add(other[i])
                if (i < first.size) ans.add(first[i])
            }
            println(ans.joinToString(""))
            return@repeat
        }

        if (cnt.count { it > 0 } == 2) {
            print('a' + a)
            print(s.filter { it != 'a' + a }.joinToString(""))
            println(s.filter { it == 'a' + a }.drop(1).joinToString(""))
            return@repeat
        }

        val nonZero = cnt.indices.filter { cnt[it] != 0 }
        print('a' + nonZero[0])
        print('a' + nonZero[1])
        print(s.filter { it == 'a' + a }.drop(1).joinToString(""))
        print('a' + nonZero[2])
        val rem = s.filter { it != 'a' + a }.toMutableList()
        rem.removeAt(rem.indices.find { rem[it] == 'a' + nonZero[1] }!!)
        rem.removeAt(rem.indices.find { rem[it] == 'a' + nonZero[2] }!!)
        println(rem.joinToString(""))
    }
}