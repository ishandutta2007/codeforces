private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
data class edge(val v : Int, val lab : Int);

fun main() {
    var tt=readInt()
    for (tc in 0..tt-1) {
        var (n,k)=readInts()
        var g=Array(n,{ArrayList<Int>()})
        for (i in 0..n-2) {
            var (u,v)=readInts()
            u-=1
            v-=1
            g[u].add(v)
            g[v].add(u)
        }
        if (k==1) {
            println("Yes");
            println("1");
            println("1");
            continue;
        }
        if (n==2) {
            println("Yes");
            println("2");
            println("1 2");
            continue;
        }
        var rt=0
        for (u in 0..n-1) {
            if (g[u].size!=1) {
                rt=u
                break
            }
        }
        var f=IntArray(n)
        var q=IntArray(n)
        var t=1
        q[0]=rt
        f[rt]=-1
        var lef=ArrayList<Int>()
        for (i in 0..n-1) {
            var u=q[i]
            var lf=true
            for (v in g[u]) if (v!=f[u]) {
                q[t]=v
                f[v]=u
                lf=false
                t+=1
            }
            if (lf) {
                lef.add(u)
            }
        }
        var mark=BooleanArray(n)
        if (lef.size<k) {
            println("No")
            continue
        }
        var croot=0
        for (i in 0..k-1) {
            var u=lef[i]
            while (u!=-1&&!mark[u]) {
                mark[u]=true
                u=f[u]
            }
            if (u==-1||u==rt) {
                croot+=1
            }
            if (croot==1&&i==k-2) {
                break
            }
        }
        var cnt=0
        for (i in 0..n-1)
            if (mark[i])
                cnt+=1
        println("Yes")
        println(cnt)
        for (i in 0..n-1)
            if (mark[i])
                print("${i+1} ")
        println()
    }
}