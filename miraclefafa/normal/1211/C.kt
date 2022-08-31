import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

data class item(val cap : Int, val cost : Int);

fun main() {
    var (n,k)=readInts()
    var kk: Long =k.toLong();
    var ans : Long =0;
    var a=ArrayList<item>()
    for (i in 0..n-1) {
        var (l,r,c)=readInts()
        kk-=l
        ans+=l.toLong()*c;
        a.add(item(r-l,c))
    }
    if (kk<0) {
        println(-1)
        return
    }
    a.sortBy({it.cost});
    for (i in 0..n-1) {
        var c=minOf(kk.toInt(),a[i].cap)
        ans+=c.toLong()*a[i].cost
        kk-=c
    }
    if (kk>0) {
        println(-1)
        return
    }
    println(ans)
}