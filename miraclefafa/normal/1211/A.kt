private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
fun main() {
    var n=readInt()
    var a=readInts()
    var mnp=0
    var mxp=0
    for (i in 0..n-1) {
        if (a[i]<a[mnp]) {
            mnp=i
        }
        if (a[i]>a[mxp]) {
            mxp=i
        }
    }
    var mdp=-1
    for (i in 0..n-1) {
        if (a[i]!=a[mnp]&&a[i]!=a[mxp]) {
            mdp=i
        }
    }
    if (a[mnp]==a[mxp]||mdp==-1) 
        println("-1 -1 -1")
    else {
        println("${mnp+1} ${mdp+1} ${mxp+1}")
    }
}