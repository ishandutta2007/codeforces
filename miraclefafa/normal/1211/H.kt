private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

data class edge(val to : Int, val lab : Int);

fun solve() {
    var n=readInt()
    var g=Array(n+1,{ArrayList<edge>()})
    var flip=IntArray(n+1)
    for (i in 0..n-2) {
        var (u,v)=readInts()
        g[u].add(edge(v,i))
        g[v].add(edge(u,i))
    }
    fun check(t:Int):Boolean {
        var dp=IntArray(n+1);
        for (i in 1..n) {
            flip[i]=0
        }
        fun dfs(u:Int, f:Int) {
            var ss=ArrayList<Int>()
            for (p in g[u]) {
                var v=p.to
                if (v==f) continue
                dfs(v,u)
                ss.add(v)
            }
            var sz=ss.size
            var pd=Array(sz+1,{BooleanArray(t+1)})
            pd[0][0]=true
            var keys=0
            for (i in 0..sz-1) {
                var key=dp[ss[i]]+1
                keys+=key
                for (j in 0..t)
                    pd[i+1][j]=pd[i][j]
                for (j in key..t)
                    pd[i+1][j]=pd[i+1][j] or pd[i][j-key]
            }
            var maxv=0
            for (j in 0..t) if (pd[sz][j]) maxv=j
            dp[u]=keys-maxv
            while (sz>0) {
                sz-=1
                if (pd[sz][maxv]) continue
                flip[ss[sz]]=1
                maxv-=dp[ss[sz]]+1
            }
        }
        dfs(1,0)
        return dp[1]<=t
    }
    var l=0
    var r=n
    while (l+1<r) {
        var md=(l+r)/2
        if (check(md)) r=md
        else l=md
    }
    check(r)
    var ans=IntArray(n-1)
    var lab=1
    fun dfs2(u:Int,f:Int,clab:Int) {
        var flab=lab+1
        lab+=1
        for (p in g[u]) {
            var v=p.to
            if (v==f) continue
            if (flip[v]==0) {
                ans[p.lab]=clab
                dfs2(v,u,clab)
            } else {
                ans[p.lab]=flab
                dfs2(v,u,flab)
            }
        }       
    }
    dfs2(1,0,1)
    println(r)
    println(ans.map({it.toString()}).joinToString(" "))
}

fun main() {
    val t=readInt()
    for (tc in 0..t-1) {
        solve()
    }
}