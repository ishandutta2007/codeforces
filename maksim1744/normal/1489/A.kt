/*
    author:  Maksim1744
    created: 02.03.2021 21:35:48
*/

fun main() {
    var n = readLine()!!.toInt()
    var b = readLine()!!.split(' ').map{ it.toInt() }
    var a = ArrayList<Int>()
    for (k in b) {
        a.add(k);
    }
    var mp = HashMap<Int, Int>();
    var k: Int = n;
    for (i in 0..n-1) {
        if (mp.contains(a[i])) {
            a[mp.getValue(a[i])] = -1;
            k -= 1;
        }
        mp.put(a[i], i);
    }
    println("$k")
    for (x in a) {
        if (x >= 0) {
            print("$x ")
        }
    }
    println()
}

/*
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