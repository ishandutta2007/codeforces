
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()

    while (t > 0){
        val s = readLn()
        val ss = s.toCharArray()
        ss.sort()

        if (ss[0] == ss.last())
            println(-1)
        else
            println(ss)

        t -= 1
    }
}