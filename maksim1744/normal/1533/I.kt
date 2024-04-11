/*
    author:  Maksim1744
    created: 29.06.2021 18:52:16
*/

import kotlin.math.*

fun dfs(v: Int, p: Int, g: ArrayList<ArrayList<Int>>, u: ArrayList<Boolean>, ks: ArrayList<Int>): Int {
    u[v] = true
    var ans: Int
    if (v < ks.size) {
        ans = ks[v]
    } else {
        ans = 1000000000
    }
    for (k in g[v]) {
        if (k == p) {
            continue;
        }
        if (u[k]) {
            ans = 0
            continue
        }
        ans = min(ans, dfs(k, v, g, u, ks))
    }
    return ans
}

fun main() {
    var (n1, n2, m) = readLine()!!.split(' ').map{ it.toInt() }
    var kk = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var k = ArrayList<Int>()
    for (x in kk) {
        k.add(x)
    }
    var g = ArrayList<ArrayList<Int>>()
    repeat(n1 + n2) {
        var gl = ArrayList<Int>()
        g.add(gl)
    }

    repeat(m) {
        var (x, y) = readLine()!!.split(' ').map{ it.toInt() }
        x = x - 1
        y = y - 1 + n1
        g[x].add(y)
        g[y].add(x)
    }

    var u = ArrayList<Boolean>()
    repeat(n1 + n2) {
        u.add(false)
    }

    var ans = 0
    for (i in 0 until n1) {
        if (!u[i]) {
            ans += dfs(i, -1, g, u, k)
        }
    }
    println(ans)
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