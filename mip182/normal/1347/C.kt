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
        var n=readInt()
        val a=arrayListOf(0)
        var f=1
        while (n>0)
        {
            if (n%10!=0)
                a.add(f*(n%10))
            n/=10
            f*=10
        }
        print(a.size-1)
        print('\n')
        for (i in 1 until a.size)
        {
            print(a[i])
            print(" ")
        }
        print('\n')

    }
}