/*
    author:  Maksim1744
    created: 02.03.2021 22:03:20
*/

fun main() {
    var q = readLine()!!.toInt()
    var L = 0
    var R = -1
    var pos = ArrayList<Int>()
    for (i in 1..200020) {
        pos.add(0)
    }
    for (qqq in 1..q) {
        var (a, iid) = readLine()!!.split(' ')
        var id = iid.toInt()
        if (a == "L") {
            pos[id] = L - 1
            L -= 1
        } else if (a == "R") {
            pos[id] = R + 1
            R += 1
        } else {
            var ans = kotlin.math.min(R - pos[id], pos[id] - L)
            println("$ans")
        }
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