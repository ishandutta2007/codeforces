import kotlin.math.*

fun cmp(a : Int, b : Int) : Boolean
{
    return a > b
}

fun input_() : Pair <Int, Int> {
    var s : String
    s = readLine()!!
    var pr = s.split(" ")
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
        var p = input_()
        n = p.first
        k = p.second
        var s : String
        s = readLine()!!.toString()
        var arr : ArrayList<Int> = arrayListOf()
        var i : Int = 0
        var sum : Int = 0
        var ans : Int = 0
        while(i < n)
        {
            if(s[i] == '1')
            {
                sum++
            }
            arr.add(i)
            i++
        }
        var st : Int = 0
        while(sum > 0)
        {
            ans++
            if(s[arr[st]] == '1')
            {
                sum--
            }
            arr.removeAt(st)
            if(arr.size > 0) {
                st = (st + k - 1) % arr.size
            }
        }
        println(ans)
        t--
    }
}