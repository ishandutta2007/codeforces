/**
 * Created by Lewin.gan on 6/16/2016.
 */
import java.util.*

fun main(args: Array<String>) {
    val s = readLine()!!.split(" ")
    val n = s[0].toInt()
    val k = s[1].toLong()
    var next = readLine()!!.split(" ").map(String::toInt).toIntArray()

    var vis = Array<Boolean>(n, {i -> false})
    var ans = Array<Int>(n, {i -> 0})
    for (i in 0..n-1) {
        next[i] -= 1
    }
    for (i in 0..n-1) {
        if(vis[i]) continue
        var c = i
        var count = 0
        var ls = ArrayList<Int>()
        do {
            ls.add(c)
            c = next[c]
            count++
        } while (c != i)
        var offset = (k % count).toInt()
        for(x in 0..ls.size-1) {
            vis[ls[x]] = true
            ans[ls[x]] = ls[(x-offset+ls.size)%ls.size]+1
        }
    }
    print(ans[0])
    for(i in 1..n-1) {
        print(" ")
        print(ans[i])
    }
    println()

}