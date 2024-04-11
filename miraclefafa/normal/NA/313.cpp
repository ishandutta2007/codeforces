import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

data class item(val cap : Int, val cost : Int, var index : Int);

fun main() {
    var n=readInt()
    var a=ArrayList<item>()
    for (i in 0..n-1) {
        var (c,p) = readInts()
        a.add(item(2*c,p,i))
    }
    var m=readInt()
    var r=readInts()
    for (i in 0..m-1) {
        a.add(item(2*r[i]+1,-1,i))
    }
    a.sortBy({it.cap})
    val q = PriorityQueue<item> { x,y-> y.cost-x.cost }
    val ansp=ArrayList<Int>()
    val ansq=ArrayList<Int>()
    var cc=0
    for (p in a) {
        if (p.cost!=-1) q.add(p)
        else {
            var x=q.poll()
            if (x==null) continue
            cc+=x.cost
            ansq.add(p.index+1)
            ansp.add(x.index+1)
        }
    }
    var z=ansp.size
    println("$z $cc")
    for (i in 0..z-1)
        println("%d %d".format(ansp[i],ansq[i]))
}