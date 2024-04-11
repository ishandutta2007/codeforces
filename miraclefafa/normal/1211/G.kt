private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve():Boolean {
    var n=readInt()
    var pa=readInts()
    var pb=readInts()
    var g=Array(n,{ArrayList<Int>()})
    for (i in 0..n-2) {
        var (u,v)=readInts()
        u-=1
        v-=1
        g[u].add(v)
        g[v].add(u)
    }
    var f=IntArray(n)
    var q=IntArray(n)
    var t=1
    q[0]=0
    f[0]=-1
    for (i in 0..n-1) {
        var u=q[i]
        for (v in g[u]) if (v!=f[u]) {
            q[t]=v
            f[v]=u
            t+=1
        }
    }
    var pu=-1
    for (i in 0..n-1) if (pa[q[i]]!=pb[q[i]])
        pu=q[i]
    if (pu==-1) {
        println("Yes");
        println("0");
        return true;
    }
    t=1
    q[0]=pu
    f[pu]=-1
    for (i in 0..n-1) {
        var u=q[i]
        for (v in g[u]) if (v!=f[u]) {
            q[t]=v
            f[v]=u
            t+=1
        }
    }
    var pv=-1
    for (i in 0..n-1) if (pa[q[i]]!=pb[q[i]])
        pv=q[i]
    var pt=ArrayList<Int>()
    while (pv!=pu) {
        pt.add(pv)
        pv=f[pv]
    }
    pt.add(pu)
    var m=pt.size
//    println(pt.map({(it+1).toString()}).joinToString(" "))
    if (m==1) {
        return false
    }
    fun checks():Boolean {
        var pc=IntArray(n)
        for (i in 0..n-1)
            pc[i]=pa[i]
        for (i in 0..m-2) 
            pc[pt[i]]=pa[pt[i+1]]
        pc[pt[m-1]]=pa[pt[0]]
        for (i in 0..n-1) if (pc[i]!=pb[i]) return false
        return true
    }
    if (checks()) {
        println("Yes");
        println(pt.size)
        println(pt.map({(it+1).toString()}).joinToString(" "))
        return true
    }
    pt.reverse()
    if (checks()) {
        println("Yes");
        println(pt.size)
        println(pt.map({(it+1).toString()}).joinToString(" "))
        return true
    }
    return false
}

fun main() {
    val t=readInt()
    for (tc in 0..t-1) {
        if (!solve()) {
            println("No");
        }
    }
}