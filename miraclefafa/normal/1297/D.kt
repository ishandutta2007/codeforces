private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
data class item(var v : Int, var pos : Int);

fun main() {
    var t=readInt()
    for (tc in 0..t-1) {
        var (n,k)=readInts()
        var a=readInts()
        var sal=ArrayList<item>();
        for (i in 0..n-1) {
            sal.add(item(a[i],i))
        }
        var ad=IntArray(n)
        sal.sortBy({-it.v})
        for (i in 1..n-1) {
            var d=minOf(k,sal[i-1].v-sal[i].v-1)
            k-=d
            sal[i].v+=d
            ad[sal[i].pos]+=d
        }
        for (i in 0..n-1) {
            ad[sal[i].pos]+=k/n
        }
        k%=n
        for (i in 0..k-1) {
            ad[sal[i].pos]+=1
        }
        for (i in 0..n-1)
            print("${ad[i]} ")
        println("")
    }
}