fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toInt() }
        val cnt = HashMap<Int, Int>()
        for (x in a) cnt[x] = cnt.getOrDefault(x, 0) + 1
        println(a.indices.find { cnt[a[it]] == 1 }!! + 1)
    }
}