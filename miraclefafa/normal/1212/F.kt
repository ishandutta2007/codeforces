private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

fun dfs(x : Long, d : Long, len : Int):Int {
    if (d==1L) return maxOf(x,-x).toInt()
    if (x==0L) return 0
    if (x>0) {
        var c=(x/d).toInt()
        var xx=x-c*d
        return minOf(dfs(xx,d/10,len-1)+c*len,dfs(xx-d,d/10,len-1)+(c+1)*len)
    } else {
        var c=((-x)/d).toInt()
        var xx=x+c*d
        return minOf(dfs(xx,d/10,len-1)+c*len,dfs(xx+d,d/10,len-1)+(c+1)*len)
    }
}

fun main() {
    var x=readLn().toLong()
    println(dfs(x,1111111111111111L,16));
}