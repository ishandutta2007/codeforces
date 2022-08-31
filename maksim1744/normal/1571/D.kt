/*
    author:  Maksim1744
    created: 07.10.2021 17:51:35
*/

import kotlin.math.*;

fun main() {
    var (n, m) = readLine()!!.split(' ').map{ it.toInt() }
    var (a, b) = readLine()!!.split(' ').map{ it.toInt() }
    m -= 1

    var ar = ArrayList<Pair<Int, Int>>()
    for (i in 0..m-1) {
        var (x, y) = readLine()!!.split(' ').map{ it.toInt() }
        ar.add(Pair(x, y))
    }

    var ans = 1

    var with_first = HashMap<Int, Int>()
    var with_last = HashMap<Int, Int>()
    var total = HashMap<Pair<Int, Int>, Int>()
    for ((x, y) in ar) {
        with_first.put(x, with_first.getOrElse(x, {0}) + 1)
        with_last.put(y, with_last.getOrElse(y, {0}) + 1)
        total.put(Pair(x, y), total.getOrElse(Pair(x, y), {0}) + 1)
    }

    for (x in 1..n) {
        for (y in 1..n) {
            if (x == y) {
                continue
            }
            var c0 = total.getOrElse(Pair(x, y), {0})
            var c1 = with_first.getOrElse(x, {0}) + with_last.getOrElse(y, {0}) - c0 * 2
            var cur = 1
            if (x == a && y == b) {
            } else if (x == a || y == b) {
                cur = c0 + 1;
            } else {
                cur = c0 + c1 + 1
            }
            ans = max(ans, cur)
        }
    }
    println(ans)

    // if (n != 2) {
    //     // first == a, last != b
    //     {
    //         var hm = HashMap<Pair<Int, Int>, Int>()
    //         for ((x, y) in ar) {
    //             if (x != a) {
    //                 continue
    //             }
    //             if (y == b) {
    //                 continue
    //             }
    //             cur = hm.getOrElse(Pair(x, y), 0)
    //             hm.put(Pair(x, y), cur + 1)
    //         }
    //         for ((key, value) in hm) {
    //             ans = max(ans, value + 1)
    //         }
    //     }
    //     // first != a, last == b
    //     {
    //         var hm = HashMap<Pair<Int, Int>, Int>()
    //         for ((x, y) in ar) {
    //             if (x == a) {
    //                 continue
    //             }
    //             if (y != b) {
    //                 continue
    //             }
    //             cur = hm.getOrElse(Pair(x, y), 0)
    //             hm.put(Pair(x, y), cur + 1)
    //         }
    //         for ((key, value) in hm) {
    //             ans = max(ans, value + 1)
    //         }
    //     }
    // }
    // {
    //     {
    //         var hm = HashMap<Pair<Int, Int>, Int>()
    //         for ((x, y) in ar) {
    //             if (x == a) {
    //                 continue
    //             }
    //             if (y == b) {
    //                 continue
    //             }
    //             cur = hm.getOrElse(Pair(x, y), 0)
    //             hm.put(Pair(x, y), cur + 1)
    //         }
    //         for ((key, value) in hm) {
    //             ans = max(ans, value + 1)
    //         }
    //     }
    // }
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