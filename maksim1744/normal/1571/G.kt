/*
    author:  Maksim1744
    created: 07.10.2021 18:41:56
*/

import kotlin.math.*;

fun main() {
    var (n, m) = readLine()!!.split(' ').map{ it.toInt() }
    var ar0 = ArrayList<Pair<Pair<Int, Int>, Long>>()
    var ar = ArrayList<Pair<Int, Long>>()
    for (i in 0..n-1) {
        var k = readLine()!!.toInt()
        var a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
        var b = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
        for (j in 0..k-1) {
            b[j] += i
        }
        for (j in k-1 downTo 0) {
            if (b[j] >= m) {
                var x = i
                var y = b[j]
                x -= y
                ar0.add(Pair(Pair(x, y), a[j].toLong()))
            }
        }
    }
    ar0.sortWith(compareBy({it.first.first}, {it.first.second}))
    for ((pr, a) in ar0) {
        ar.add(Pair(pr.second, a))
    }

    var xx = ArrayList<Int>()
    for ((b, a) in ar) {
        xx.add(b)
    }
    xx.sort()
    var x = ArrayList<Int>()
    for (u in xx) {
        if (x.size == 0 || x[x.size-1] != u) {
            x.add(u)
        }
    }

    for (i in 0..ar.size-1) {
        var L = -1
        var R = x.size
        while (R - L > 1) {
            var C = (L + R) / 2
            if (x[C] < ar[i].first) {
                L = C
            } else {
                R = C
            }
        }
        ar[i] = Pair(R, ar[i].second)
    }

    // var t = HashMap<Int, Long>()

    var t = ArrayList<Long>()
    for (i in 0..x.size-1) {
        t.add(0)
    }

    fun getMax(rr: Int): Long {
        // return t.getOrElse(rr, {0.toLong()})
        var r = rr
        var res = 0.toLong()
        while (r >= 0) {
            res = max(res, t[r])
            if (r == 0) {
                break
            }
            r = (r and (r+1)) - 1
        }
        return res
    }

    fun update(ii: Int, v: Long) {
        // t[ii] = max(v, t.getOrElse(ii, {0.toLong()}))
        var i = ii
        while (i < t.size) {
            t[i] = max(t[i], v)
            i = (i or (i + 1))
        }
    }

    for ((b, a) in ar) {
        var cur = getMax(b - 1)
        cur += a
        update(b, cur)
    }

    println(getMax(t.size - 1))
    // var ans = 0.toLong()
    // for ((key, value) in t) {
    //     ans = max(ans, value)
    // }

    // println(ans)

    // for ((x, y) in ar0) {
    //     print("((${x.first}, ${x.second}), $y) ")
    // }
    // println()
}

/*

read array: readLine()!!.split(' ').map{ it.toInt() }.toMutableList()

var mp = HashMap<Int, Int>();
mp.getValue(k)
if (mp.contains(k))
mp.put(a, b)

val s = StringBuilder("test");
s[0] = 'g';
s.append(s);
println(s); // gestgest



credits: aleks5d

    
   )))

:
kotlinc A.kt -include-runtime -d A.jar
java -jar A.jar

  :
Pair<T1, T2> - 
Pair(a, b) -  
     - 

  (  ?)     
    !

    , ?
 : arr.sort()
  /    
arr.sortWith(compareBy({it.first}, {it.second}))  arr.sortWith(compareBy({it[0]}, {it[1]}))   

   
  ArrayList
ArrayList<Int>()
push_back = add
pop_back = removeAt(lastIndex)
arrayListOf()
list.binarySearch()

HashMap<String,Int>()

PriorityQueue<Pair<Long,Int>>({x,y ->
    x.first.compareTo(y.first)})

var A = arrayListOf(Pair(1,3),Pair(2,2),Pair(3,1))
val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
    x.second.compareTo(y.second)})

             )))
*/