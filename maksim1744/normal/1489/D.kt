/*
    author:  Maksim1744
    created: 02.03.2021 21:56:54
*/

fun main() {
    var n = readLine()!!.toInt()
    var a = ArrayList<String>()
    for (i in 0..n-1) {
        var s = readLine()!!
        a.add(s)
    }
    a.sortWith(compareBy({it.length}))
    for (i in 1..n-1) {
        var ok = 0
        for (j in 0..a[i].length - a[i - 1].length) {
            var ook = 1
            for (k in 0..a[i - 1].length-1) {
                if (a[i][k + j] != a[i - 1][k]) {
                    ook = 0;
                    break;
                }
            }
            if (ook == 1) {
                ok = 1;
                break;
            }
        }
        if (ok == 0) {
            println("NO")
            return
        }
    }
    println("YES")
    for (s in a) {
        println("$s")
    }
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