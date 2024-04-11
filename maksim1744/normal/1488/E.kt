/*
    author:  Maksim1744
    created: 09.03.2021 17:54:21
*/

import kotlin.math.*;

fun test_case() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var last = HashMap<Int, Int>()
    var not_alone = HashSet<Int>()
    var with = ArrayList<Int>()
    for (i in 0..n-1) {
        with.add(-1)
    }
    for (i in 0..n-1) {
        if (last.contains(a[i])) {
            with[last.getValue(a[i])] = i;
            with[i] = last.getValue(a[i]);
            not_alone.add(a[i]);
        } else {
            last.put(a[i], i)
        }
    }

    var ans = 1
    var dp = ArrayList<Int>()
    for (i in 1..n+10) {
        dp.add(1000000000)
    }
    dp[0] = -1000000000
    for (i in 0..n-1) {
        if (with[i] < i) {
            continue;
        }
        var l = -1
        var r = dp.size.toInt()
        while (r - l > 1) {
            var c = (l + r) / 2
            if (dp[c] <= -with[i]) {
                l = c;
            } else {
                r = c;
            }
        }
        var u = 0
        if (i + 1 < with[i]) {
            u += 1
        }
        ans = max(ans, r * 2 + u)
        dp[r] = -with[i]
    }
    println("$ans")
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



  aleks5d

    
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