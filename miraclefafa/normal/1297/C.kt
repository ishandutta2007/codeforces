private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
fun main() {
    var t=readInt()
    for (tc in 0..t-1) {
        var n=readInt()
        var a=readInts()
        var b=IntArray(n)
        var repl=100000
        var pos=-1
        var s=0
        for (i in 0..n-1) {
            if (a[i]>0) {
                s+=a[i]
                if (a[i]<repl) {
                    repl=a[i]
                    pos=i
                }
                b[i]=1
            } else if (a[i]<0) {
                if (-a[i]<repl) {
                    repl=-a[i]
                    pos=i
                }
            }
        }
        println(s-repl)
        b[pos]=b[pos] xor 1
        for (i in 0..n-1)
            print(b[i])
        println("")
    }
}