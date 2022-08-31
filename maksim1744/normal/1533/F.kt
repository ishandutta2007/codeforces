/*
    author:  Maksim1744
    created: 29.06.2021 17:59:39
*/

import kotlin.math.*

fun main() {
    var s = readLine()!!
    var n = s.length

    var pref0 = IntArray(n) {0}
    var pref1 = IntArray(n) {0}
    for (i in 0 until n) {
        if (i != 0) {
            pref0[i] = pref0[i - 1]
            pref1[i] = pref1[i - 1]
        }
        if (s[i] == '0') {
            pref0[i] += 1
        } else {
            pref1[i] += 1
        }
    }

    var with_pref0 = IntArray(n * 2 + 5) {n}
    var with_pref1 = IntArray(n * 2 + 5) {n}
    for (i in n-1 downTo 0) {
        with_pref0[pref0[i]] = i
        with_pref1[pref1[i]] = i
    }

    for (k in 1..n) {
        var cur = 0
        var ans = 0
        while (cur != n) {
            var cur0 = 0
            var cur1 = 0
            if (cur != 0) {
                cur0 = pref0[cur - 1]
                cur1 = pref1[cur - 1]
            }

            var next = max(with_pref0[cur0 + k + 1], with_pref1[cur1 + k + 1])
            cur = next
            ans += 1
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