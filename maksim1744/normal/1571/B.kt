/*
    author:  Maksim1744
    created: 07.10.2021 17:38:56
*/

fun test_case() {
    var n = readLine()!!.toInt()
    var (a, va) = readLine()!!.split(' ').map{ it.toInt() }
    var (c, vc) = readLine()!!.split(' ').map{ it.toInt() }
    var b = readLine()!!.toInt()

    for (vb in va..vc) {
        var ok = true
        if (b - a < vb - va) {
            ok = false
        }
        if (c - b < vc - vb) {
            ok = false
        }
        if (ok) {
            println(vb)
            return
        }
    }
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