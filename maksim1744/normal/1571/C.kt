/*
    author:  Maksim1744
    created: 07.10.2021 17:42:45
*/

import kotlin.math.*;

fun test_case() {
    var n = readLine()!!.toInt()
    var mink = 0
    var maxk = 1000000
    for (i in 0..n-1) {
        var (s, t, rr) = readLine()!!.split(' ')
        var r = rr.toInt()
        var has = 0
        while (has < s.length && has < t.length && s[s.length - 1 - has] == t[t.length - 1 - has]) {
            has += 1
        }
        if (r == 0) {
            mink = max(mink, has + 1)
        } else {
            maxk = min(maxk, has)
        }
    }
    if (mink > maxk) {
        mink = maxk + 1;
    }
    println(maxk - mink + 1)
    for (i in mink..maxk) {
        print("$i ")
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

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}