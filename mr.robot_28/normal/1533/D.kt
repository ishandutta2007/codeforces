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
val mod1 : Long = (1e9 + 7).toLong()
val mod2 : Long = 998244353
var pw1 : ArrayList<Long> = arrayListOf()
var pw2 : ArrayList<Long> = arrayListOf()
fun main()
{
    pw1.add(1)
    pw2.add(1)
    var c : Int = 1
    while(c <= 11)
    {
        pw1.add(pw1[pw1.size - 1] * 28 % mod1)
        pw2.add(pw2[pw2.size - 1] * 28 % mod2)
        c++
    }
    var n : Int
    var m : Int
    var p = input_()
    n = p.first
    m = p.second
    var a : ArrayList<String> = arrayListOf()
    var i : Int = 0
    var mp = mutableMapOf(Pair(0L, 0L) to 0)
    while(i < n)
    {
        var s : String
        s = readLine()!!.toString()
        a.add(s)
        var j : Int = 0
        var hs : Pair <Long, Long> = Pair(0, 0)
        while(j < m)
        {
            var hs1 = hs.copy(first = (hs.first + pw1[j] * (s[j].toInt() - 'a'.toInt() + 1)) % mod1,
            second = (hs.second + pw2[j] * (s[j].toInt() - 'a'.toInt() + 1)) % mod2)
            hs = hs1.copy()
            j++
        }
        mp[hs] = 1
        i++
    }
    var q : Int = readLine()!!.toInt()
    i = 0
    while(i < q)
    {
        var s : String
        s = readLine()!!.toString()
        var j : Int = 0
        var ans : Int = 0
        var mp1 = mutableMapOf(Pair(0L, 0L) to 0)
        while(j < m + 1)
        {
            var k : Int = 0
            var it1 : Int = 0
            var hs : Pair <Long, Long> = Pair(0L, 0L)
            while(k < m + 1)
            {
                if(k != j)
                {
                    var hs1 = hs.copy(first = (hs.first + pw1[it1] * ((s[k].toInt() - 'a'.toInt()) + 1)) % mod1,
                        second = (hs.second + pw2[it1] * ((s[k].toInt() - 'a'.toInt()) + 1)) % mod2)
                    hs = hs1.copy()
                    it1++
                }
                k++
            }
            if(mp1[hs] == null)
            {
                mp1[hs] = 1
                var pr : Int? = mp[hs]
                if(pr != null)
                {
                    ans += pr
                }
            }
            j++
        }
        i++
        println(ans)
    }
}