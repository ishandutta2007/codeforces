fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

class Number(val nr: Int,val gain: Int) {}

fun run() {
    val (n) = readInts()
    val opt = mutableListOf<Number>()
    val pmn = IntArray(n+1){-1}
    for(i in 2..n) if(pmn[i]==-1) for(j in i..n step i) if(pmn[j]==-1) pmn[j]=i
    var div = IntArray(n+1)
    div[1] = 1
    for(i in 2..n) {
        val p=pmn[i]
        var cnt=0
        var x=i
        while(x%p==0) { x/=p; cnt++; }
        div[i]=div[x]*(cnt+1)
    }
    for(i in 1..n) opt.add(Number(i,(n/i-1)-(div[i]-1)))
    opt.sortBy{-it.gain}

    val ans = LongArray(n)
    ans[n-1]=0
    for(i in n-2 downTo 0) ans[i]=ans[i+1]+opt[n-2-i].gain
    println(ans.joinToString(" "))
}

fun main() {
    run()
}