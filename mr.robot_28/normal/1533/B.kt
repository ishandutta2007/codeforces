import kotlin.math.*

fun cmp(a : Int, b : Int) : Boolean
{
    return a > b
}


fun main()
{
    var t : Int
    t = readLine()!!.toInt()
    while(t > 0)
    {
        var n : Int
        n = readLine()!!.toInt()
        var a : ArrayList<Int> = arrayListOf()
        var s : String
        s = readLine()!!
        var t1 = s.split(" ")
        for(x in t1)
        {
            a.add(x.toInt())
        }
        var fl : Boolean = false
        var i : Int = 0
        while(i + 1 < n)
        {
            if((a[i + 1] - a[i]) % 2 == 0)
            {
                fl = true
            }
            i++
        }
        if(fl)
        {
            println("YES")
        }
        else
        {
            println("NO")
        }
        t--
    }
}