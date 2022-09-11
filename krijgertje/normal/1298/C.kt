fun main() {
    val n=readLine()!!.toInt()
    val s=readLine()!!+"!"
    var cnt=0; var ret=0
    for(c in s) if(c=='x') ++cnt; else { ret+=kotlin.math.max(0,cnt-2); cnt=0; }
    println(ret)
}