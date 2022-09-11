fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

const val ALPH = 4
const val MOD = 998244353

class SVal(var fst: Int, var lst: Int) {
    val ways = Array(ALPH, { Array(ALPH, { 0 }) })
}

fun merge(a: SVal, b: SVal): SVal {
    val c = SVal(a.fst,b.lst)
    for(i in 0..ALPH-1) for(j in 0..ALPH-1) {
        var sum = 0
        if(a.lst==0) {
            for(k in 0..ALPH-1) {
                c.ways[i][j] = ((c.ways[i][j] + a.ways[i][k].toLong() * sum) % MOD).toInt()
                sum = (sum + b.ways[k][j]) % MOD
                if(a.lst == b.fst) c.ways[i][j] = ((c.ways[i][j] + a.ways[i][k].toLong() * b.ways[k][j]) % MOD).toInt()
            }
        } else {
            for(k in ALPH-1 downTo 0) {
                c.ways[i][j] = ((c.ways[i][j] + a.ways[i][k].toLong() * sum) % MOD).toInt()
                sum = (sum + b.ways[k][j]) % MOD
                if(a.lst == b.fst) c.ways[i][j] = ((c.ways[i][j] + a.ways[i][k].toLong() * b.ways[k][j]) % MOD).toInt()
            }
        }
    }
    return c
}

fun run() {
    val (n,nq) = readInts()
    val init = readInts()
    val s = Array(4*(n-1), {SVal(0,0)})
    fun sbuild(x: Int, l: Int, r: Int) {
        if(l==r) {
            s[x]=SVal(init[l],init[l])
            for(i in 0..ALPH-1) s[x].ways[i][i]=1
        } else {
            val m=l+(r-l)/2
            sbuild(2*x+1,l,m)
            sbuild(2*x+2,m+1,r)
            s[x]=merge(s[2*x+1],s[2*x+2])
        }
    }
    fun sflip(x: Int, l: Int, r: Int, IDX: Int) {
        if(l==r) {
            s[x].fst=1-s[x].fst
            s[x].lst=1-s[x].lst
        } else {
            val m=l+(r-l)/2
            if(IDX<=m) sflip(2*x+1,l,m,IDX) else sflip(2*x+2,m+1,r,IDX)
            s[x]=merge(s[2*x+1],s[2*x+2])
        }
    }
    sbuild(0,0,n-2)
    repeat(nq) {
        val (idx) = readInts().map{it-1}
        sflip(0,0,n-2,idx)
        /*print("${s[0].fst}..${s[0].lst} [")
        for(i in 0..ALPH-1) { 
            print("[")
            for(j in 0..ALPH-1) { 
                if(j!=0) print(",")
                print(s[0].ways[i][j])
            }
            print("]")
        }
        println()*/
        var ans = 0
        for(i in 0..ALPH-1) for(j in 0..ALPH-1) for(k in 0..ALPH-1) {
            if(s[0].lst==0&&k>j||s[0].lst==1&&k<=j) continue
            ans = (ans + s[0].ways[i][j]) % MOD
        }
        println(ans)
    }
    
}

fun main() {
    run()
}