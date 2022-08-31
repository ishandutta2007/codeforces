private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (n,k)=readInts()
    var a=readInts().toMutableList()
    a.sort()
    if (k==0) {
        if (a[0]==1) println(-1)
        else println(a[0]-1)
        return
    }
    if (k==n||a[k-1]!=a[k]) {
        println(a[k-1])
        return 
    }
    println(-1)
}