fun main() {
    var tt = readLine()!!.toInt()
    repeat(tt) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map{it.toInt()}.toIntArray()
        val t = a.indices.sortedBy{a[it]}
        var nxtEv = a[t[0]]
        var li = 0
        var ri = n - 1
        repeat(n) {
            if (it == nxtEv) {
                print("${t[li++] + 1} ")
                nxtEv += a[t[li]]
            } else {
                print("${t[ri--] + 1} ")
            }
        }
        println()
    }
}