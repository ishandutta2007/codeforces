/*
    author:  Maksim1744
    created: 02.03.2021 22:17:48
*/

fun main() {
    var (n, m) = readLine()!!.split(' ').map{ it.toInt() }
    var a = readLine()!!.split(' ').map{ it.toLong() }.toMutableList()
    var e = ArrayList<Pair<Long, Pair<Int, Int>>>()
    var im = 0
    for (i in 1..n-1) {
        if (a[i] < a[im]) {
            im = i
        }
    }
    for (i in 0..n-1) {
        if (i != im) {
            e.add(Pair(a[i] + a[im], Pair(i, im)))
        }
    }
    for (i in 1..m) {
        var (x, y, w) = readLine()!!.split(' ').map{ it.toLong() }
        e.add(Pair(w, Pair(x.toInt() - 1, y.toInt() - 1)))
    }
    e.sortWith(compareBy({it.first}))

    var rk = ArrayList<Int>()
    var p = ArrayList<Int>()
    for (i in 0..n-1) {
        rk.add(1)
        p.add(i)
    }

    fun par(v: Int): Int {
        if (v == p[v]) {
            return v;
        }
        var k = par(p[v]);
        p[v] = k;
        return k
    }

    fun un(uu: Int, vv: Int) {
        var u = par(uu)
        var v = par(vv)
        if (u == v) {
            return
        }
        if (rk[u] > rk[v]) {
            var k = u
            u = v
            v = k
        }
        rk[v] += rk[u]
        p[u] = v
    }

    fun check(u: Int, v: Int): Boolean {
        return (par(u) == par(v))
    }

    var ans: Long = 0

    for (el in e) {
        var (w, uv) = el
        var (u, v) = uv
        if (check(u, v)) {
            continue
        }
        ans += w
        un(u, v)
    }
    println("$ans")
}

/*

read array: readLine()!!.split(' ').map{ it.toInt() }.toMutableList()

var mp = HashMap<Int, Int>();
mp.getValue(k)
if (mp.contains(k))
mp.put(a, b)




 aleks5d   !!!

    
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