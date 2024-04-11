/*
    author:  Maksim1744
    created: 09.03.2021 17:39:33
*/

fun test_case() {
    var (n, k) = readLine()!!.split(' ').map{ it.toInt() }
    var s = readLine()!!
    var groups = 0
    var balance = 0
    for (c in s) {
        if (c == '(') {
            balance += 1;
        } else {
            balance -= 1;
        }
        if (balance == 0) {
            groups += 1;
        }
    }
    var ans = groups;
    n -= groups * 2;
    n /= 2;
    if (k > n) {
        k = n;
    }
    ans += k;
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