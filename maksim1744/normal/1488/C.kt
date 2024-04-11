/*
    author:  Maksim1744
    created: 09.03.2021 17:42:37
*/

import kotlin.math.*;

fun test_case() {
    var (n, x, y) = readLine()!!.split(' ').map{ it.toInt() }
    if (x > y) {
        var z = x;
        x = y;
        y = z;
    }
    fun getpath(n: Int, x: Int) : Int {
        return n - 1 + min(n - x, x - 1);
    }
    var ans = getpath(n, x);
    for (i in x..y-1) {
        ans = min(ans, max(getpath(i, x), getpath(n - i, y - i)));
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