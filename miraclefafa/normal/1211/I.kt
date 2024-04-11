import java.util.*
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
data class edge(val v : Int, val lab : Int);

fun main(args: Array<String>) {
    var (n,m)=readInts()
    var pw=LongArray(n+1)
    var mod:Long=10000000000000017L;
    pw[0]=23333
    for (i in 1..n) {
        pw[i]=(pw[i-1]*13331+23333)%mod;
    }
    var pa=IntArray(m)
    var pb=IntArray(m)
    var g=LongArray(n)
    for (i in 0..m-1) {
        var (u,v)=readInts()
        u-=1
        v-=1
        pa[i]=u
        pb[i]=v
        g[u]+=pw[v]
        g[v]+=pw[u]
    }
    var bel=IntArray(n)
    var rep=ArrayList<Int>()
    var cp=0
    for (i in 0..n-1) {
        bel[i]=-1
        for (j in 0..cp-1) {
            if (g[i]==g[rep[j]]) {
                bel[i]=j
                break            
            }
        }
        if (bel[i]==-1) {
            bel[i]=cp
            rep.add(i)
            cp+=1
        }
    }
    var gg=Array(cp,{IntArray(cp)})
    for (i in 0..m-1) {
        var u=bel[pa[i]]
        var v=bel[pb[i]]
        gg[u][v]=1
        gg[v][u]=1
    }
    fun check(x:Int):Boolean {
        return x==1||x==2||x==4||x==8;
    }
    var vis=BooleanArray(16)
    var lab=IntArray(cp)
    fun dfs(u:Int):Boolean {
        if (u==cp) {
            for (i in 0..n-1) {
                print(lab[bel[i]])
                print(" ")
            }
            print("\n");
            return true
        } else {
            for (i in 0..15) if (!vis[i]) {
                vis[i]=true
                lab[u]=i
                var fg=true
                for (v in 0..u-1) {
                    if (gg[u][v]==1&&!check(lab[u] xor lab[v])) { fg=false; break; }
                    if (gg[u][v]==0&&check(lab[u] xor lab[v])) { fg=false; break; }
                }
                if (fg) {
                    if (dfs(u+1)) return true
                }
                vis[i]=false
            }
            return false
        }
    }
    dfs(0)
}