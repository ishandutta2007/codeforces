private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
data class item(val v : Int, val pos : Int);

fun main() {
    var n=readInt()
    var a=readInts()
    var l=0
    var r=n
    var ans=CharArray(n)
    fun check(mid:Int):Int {
        var cnt=IntArray(mid+1)
        var l=ArrayList<item>()
        var r=ArrayList<item>()
        for (i in 0..n-1) {
            if (a[i]>mid) {
                ans[i]='B'
                continue
            }
            if (cnt[a[i]]==2) {
                return 0
            }
            if (cnt[a[i]]==0) {
                ans[i]='R'
                l.add(item(a[i],i))
            } else {
                ans[i]='G'
                r.add(item(a[i],i))
            }
            cnt[a[i]]+=1
        }
        for (i in 1..mid) {
            if (cnt[i]!=2) return 0
        }
        l.sortBy({it.pos})
        r.sortBy({it.pos})
        for (i in 0..mid-1) {
            if (l[i].v!=r[i].v) return 0
        }
        return 1
    }
    while (l+1<r) {
        var mid=(l+r)/2
        if (check(mid)==1) l=mid
        else r=mid
    }
    check(l)
    println(ans.joinToString(""))
}