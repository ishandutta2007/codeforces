private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
fun main() {
    var n=readInt()
    var a=readInts()
    var mx=a.max()
    var ans:Long=0;
    var pos=0
    for (i in 0..n-1) 
        if (a[i]==mx) pos=i
    ans=mx!!.toLong();
    ans=(ans-1)*n+pos+1
    println(ans)
}