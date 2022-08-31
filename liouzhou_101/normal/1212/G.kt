import java.util.*
import kotlin.math.*

private fun readString() = readLine()!! // string line
private fun readInt() = readString().toInt() // single int
private fun readLong() = readString().toLong()
private fun readStrings() = readString().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

val INF = 1e9

fun main(args: Array<String>)
{
    var (n, l) = readInts()
    var x = Array<Int>(n+1, {x -> 0})
    var b = Array<Int>(n+1, {x -> 0})
    for (i in 1..n)
    {
        var (t1, t2) = readInts()
        x[i] = t1
        b[i] = t2
    }
    var d = Array<Array<Double>>(n+1, {x->arrayOf<Double>()})
    for (i in 1..n)
        for (j in 0..i-1)
        	d[i] += arrayOf(sqrt(abs(x[i]-x[j]-l).toDouble()))
    var L = 0.0
    var R = 1000.0
    var m = R
    var f = Array<Double>(n+1, {x -> 0.0})
    for (k in 0..80)
    {
        m = (L+R)*0.5
        for (i in 1..n)
        {
            var cur = INF
            for (j in 0..i-1)
            	cur = minOf(cur, f[j]+d[i][j])
            f[i] = cur-m*b[i]
        }
        if (f[n] > 0)
        	L = m
        else
        	R = m
    }
    fun solve(i: Int)
    {
        if (i == 0) return
        for (j in 0..i-1)
        	if (f[j]+d[i][j]-m*b[i] == f[i])
        	{
        		solve(j)
        		break
            }
        print("$i ")
    }
    solve(n)
}