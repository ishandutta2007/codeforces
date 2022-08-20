/*
    author:  Maksim1744
    created: 09.03.2021 17:36:23
*/

fun test_case() {
    var (x, y) = readLine()!!.split(' ').map{ it.toInt() }
    var ans = y % x;
    y -= y % x;
    y /= x;
    while (y != 0) {
        ans += y % 10;
        y /= 10;
    }
    println("$ans");
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