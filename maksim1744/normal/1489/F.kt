/*
    author:  Maksim1744
    created: 02.03.2021 22:12:33
*/

fun main() {
    var (n, m, k) = readLine()!!.split(' ').map{ it.toInt() }
    var a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var l = -1
    var r = n
    while (r - l > 1) {
        var c = (l + r) / 2
        var need = 1
        var cur = 0
        for (i in c..n-1) {
            if (cur + a[i] > k) {
                cur = 0
                need += 1
            }
            cur += a[i]
        }
        if (need <= m) {
            r = c
        } else {
            l = c
        }
    }
    r = n - r;
    println("$r")
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