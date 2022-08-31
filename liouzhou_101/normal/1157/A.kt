private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()

fun f(tx: Int) : Int
{
    var x = tx
    x += 1
    while (x%10 == 0)
    {
        x /= 10
    }
    return x
}

fun main(args: Array<String>)
{
    var n = readInt()
    var H = HashSet<Int>()
    while (H.add(n))
    {
        n = f(n)
    }
    println(H.size)
}