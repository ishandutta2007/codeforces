import kotlin.math.*


fun run() {
    val n=readLine()!!.toInt()
    val a=readLine()!!.split(" ").map{it.toInt()}
    var neg=-1; var pos=-1
    for(i in 0 until n) {
        if(a[i]>0&&(pos==-1||a[i]<a[pos])) pos=i
        if(a[i]<0&&(neg==-1||a[i]>a[neg])) neg=i
    }
    val toggle=if(neg!=-1&&(pos==-1||-a[neg]<a[pos])) neg else pos
    assert(toggle!=-1)
    val sum=a.filter{it>0}.sum()
    var ret=IntArray(n){if(a[it]>0) 1 else 0}
    ret[toggle]=1-ret[toggle]
    println(sum-abs(a[toggle]))
    println(ret.joinToString(""))
}

fun main() {
    val ncase=readLine()!!.toInt()
    for(i in 1..ncase) run()
}