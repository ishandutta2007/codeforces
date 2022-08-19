/*
    author:  Maksim1744
    created: 29.06.2021 17:50:35
*/

import kotlin.math.max;

fun main() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var b = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    a.sort()
    b.sort()

    var pref = IntArray(n) { 0 }
    var suf = IntArray(n) { 0 }
    pref[0] = b[0] - a[0]
    for (i in 1 until n) {
        pref[i] = max(pref[i - 1], b[i] - a[i])
    }
    suf[n - 1] = b[n] - a[n - 1]
    for (i in n-2 downTo 0) {
        suf[i] = max(suf[i + 1], b[i + 1] - a[i])
    }

    var m = readLine()!!.toInt()
    var que = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    for (c in que) {
        var L = -1
        var R = n
        while (R - L > 1) {
            var C = (L + R) / 2
            if (a[C] <= c) {
                L = C
            } else {
                R = C
            }
        }

        var pos = R
        var ans = b[pos] - c
        if (pos != 0) {
            ans = max(ans, pref[pos - 1])
        }
        if (pos != n) {
            ans = max(ans, suf[pos])
        }
        print("$ans ")
    }
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