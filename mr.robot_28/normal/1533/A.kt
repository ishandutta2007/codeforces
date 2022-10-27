import kotlin.math.*

fun cmp(a : Int, b : Int) : Boolean
{
    return a > b
}
fun input_() : Pair <Int, Int>
{
    var str : String = readLine()!!.toString()
    var pr  = str.split(" ")
    return Pair(pr[0].toInt(), pr[1].toInt())
}

fun main()
{
    var t : Int
    t = readLine()!!.toInt()
    while(t > 0)
    {
        var n : Int
        var k : Int
        var x = input_()
        n = x.first
        k = x.second
        var i : Int = 0
        var ans : Int = 0
        while(i < n)
        {
            var l : Int
            var r : Int
            x = input_()
            l = x.first
            r = x.second
            if(l <= k)
                ans = max(ans, r - k + 1)
            i++
        }
        println(ans)
        t--
    }
}