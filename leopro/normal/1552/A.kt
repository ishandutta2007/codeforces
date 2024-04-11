fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()
        val s = readLine()!!.toCharArray()
        val t = s.sortedArray()
        println(s.indices.count { s[it] != t[it] })
    }
}