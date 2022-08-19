/*
    author:  Maksim1744
    created: 07.10.2021 20:03:35
*/

fun test_case() {
    var n = readLine()!!.toInt()
    var LL = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var RR = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()

    var xl: Int
    var xr: Int
    var inf = 1010000000
    run {
        var L = -inf
        var R = inf;
        var rs = ArrayList<Int>()
        for (k in RR) {
            rs.add(k)
        }
        rs.sort()
        while (R - L > 1) {
            var C = (L + R) / 2
            var ok = true
            var ind = 0
            for (i in 0..n) {
                while (ind < n && rs[ind] <= C + i - 1) {
                    ind += 1
                }
                if (ind > i) {
                    ok = false
                }
            }
            if (ok) {
                L = C
            } else {
                R = C
            }
        }
        xr = L
    }
    run {
        var L = -inf
        var R = inf;
        var ls = ArrayList<Int>()
        for (k in LL) {
            ls.add(k)
        }
        ls.sort()
        while (R - L > 1) {
            var C = (L + R) / 2
            var ok = true
            var ind = 0
            for (i in 1..n) {
                while (ind < n && ls[ind] <= C + i - 1) {
                    ind += 1
                }
                if (ind < i) {
                    ok = false
                }
            }
            if (ok) {
                R = C
            } else {
                L = C
            }
        }
        xl = R
    }
    if (xl > xr) {
        println(-1)
        return
    }
    var L = LL
    var R = RR
    var x = xl
    var ord = ArrayList<Pair<Int, Int>>()
    for (i in 0..n-1) {
        ord.add(Pair(L[i], i))
    }
    ord.sortWith(compareBy({it.first}, {it.second}))
    var ss = sortedSetOf(0.toLong())
    ss.remove(0.toLong())
    var M = 1000000.toLong()
    var ind = 0
    var ans = ArrayList<Int>()
    for (i in 0..n-1) {
        ans.add(-1)
    }
    // for ((x, y) in ord) {
    //     println("$x, $y")
    // }
    println(x)
    for (i in 1..n) {
        while (ind < n && ord[ind].first <= x + i - 1) {
            var ii = ord[ind].second
            ss.add(R[ii].toLong() * M + ii.toLong())
            ind += 1
        }
        var xx = ss.pollFirst()
        var ii = xx % M
        // println("$xx, $ii")
        // ans[ii.toInt()] = i
        print("${ii.toInt()+1} ")
        ss.remove(xx)
    }

    // for (k in ans) {
    //     print("$k ")
    // }
    println()
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

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}