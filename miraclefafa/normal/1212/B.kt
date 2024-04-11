private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var n=readInt()
    var s=readLn()
    var cnt=Array(26,{IntArray(26)})
    var mpo=-1
    var t=""
    for (i in 0..n-2) {
        var p=s[i].toInt()-'A'.toInt()
        var q=s[i+1].toInt()-'A'.toInt()
        cnt[p][q]+=1
        if (cnt[p][q]>mpo) {
            mpo=cnt[p][q]
            t=s.substring(i,i+2)
        }
    }
    println(t)
}