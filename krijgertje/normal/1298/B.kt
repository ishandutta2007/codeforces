fun main() {
    val n=readLine()!!.toInt()
    val a=readLine()!!.split(" ").map({it.toInt()})
    var seen = HashSet<Int>()
    var ret = ArrayList<Int>()
    for(x in a.reversed()) if(seen.add(x)) ret.add(x)
    println(ret.size)
    println(ret.reversed().joinToString(" "))
}