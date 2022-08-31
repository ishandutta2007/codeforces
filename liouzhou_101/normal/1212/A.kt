private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>)
{
    var (n, k) = readInts()
    for (i in 1..k)
    {
        if (n%10 == 0) n /= 10
        else n --
    }
    println(n)
}