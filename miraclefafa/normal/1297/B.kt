private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
fun main() {
    var t=readInt()
    for (i in 0..t-1) {
        var n=readInt()
        var a=IntArray(n)
        var b=IntArray(n)
        for (j in 0..n-1) {
            var (p,q)=readInts()
            a[j]=p
            b[j]=q
        }
        var day=-1
        fun test(x:Int):Boolean {
            var c0=0
            for (k in 0..n-1)
                if (a[k]<=x&&x<=b[k]) c0+=1
            return c0==1
        }
        for (j in 0..n-1) {
            if (test(a[j])) {
                day=a[j]
                break
            }
            if (test(a[j]-1)) {
                day=a[j]-1
                break
            }
            if (test(b[j])) {
                day=b[j]
                break
            }
            if (test(b[j]+1)) {
                day=b[j]+1
                break
            }
        }
        println("${day}")
    }
}