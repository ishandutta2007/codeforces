private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
    var t=readInt()
    while (t-->0)
    {
        var (a1,b1)=readLongs()
        var (a2,b2)=readLongs()
        if (a1>b1)
        {
            val x=a1
            val y=b1
            a1=y
            b1=x
        }
        if (a2>b2)
        {
            val x=a2
            val y=b2
            a2=y
            b2=x
        }
        if (a1>a2)
        {
            val x=a1
            val y=a2;
            a1=y
            a2=x
            val xx=b1
            val yy=b2;
            b1=yy
            b2=xx
        }
        if (b1==b2&&a1+a2==b1)
        {
            print("Yes\n")
        }
        else
            print("No\n")

    }
}