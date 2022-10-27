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
fun input_1() : ArrayList <Long>{
    var s : String = readLine()!!.toString()
    var s1 = s.split(" ")
    var a : ArrayList<Long> = arrayListOf()
    for(x in s1)
        a.add(x.toLong())
    return a
}
fun main()
{
    var n : Int = readLine()!!.toInt()
    var a : ArrayList <Long> = input_1()
    var b : ArrayList <Long> = input_1()
    var m = readLine()!!.toInt()
    var c : ArrayList <Long> = input_1()
    a.sort()
    b.sort()
    var pref = LongArray(n)
    var suf = LongArray(n)
    var n1 : Int = n - 1
    for(i in 0..n1)
    {
        pref[i] = b[i] - a[i]
        if(i != 0)
        {
            pref[i] = max(pref[i], pref[i - 1])
        }
    }
    for(i in n1 downTo 0)
    {
        suf[i] = b[i + 1] - a[i]
        if(i != n1)
        {
            suf[i] = max(suf[i], suf[i + 1])
        }
    }
    for(x in c)
    {
        var L : Int = -1
        var R : Int = n
        while(R -  L> 1)
        {
            var midd : Int = (R + L) / 2
            if(a[midd] <x)
            {
                L = midd
            }
            else
            {
                R = midd
            }
        }
        var ans : Long = -1000000000
        if(L != -1)
        {
            ans = max(ans, pref[L])
        }
        if(R != n)
        {
            ans = max(ans, suf[R])
        }
        ans = max(ans,  b[R] - x)
        print("$ans ")
    }
}