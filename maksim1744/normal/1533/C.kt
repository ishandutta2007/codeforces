/*
    author:  Maksim1744
    created: 29.06.2021 17:41:26
*/

fun test_case() {
    var (n, k) = readLine()!!.split(' ').map{ it.toInt() }
    var u = BooleanArray(n) { false }
    var s = readLine()!!
    var ans = 0
    var left = 0
    for (i in 0 until n) {
        if (s[i] == '1') {
            left += 1
        }
    }
    var cur = 0
    while (left != 0) {
        var steps = 0
        u[cur] = true
        ans += 1
        if (s[cur] == '1') {
            left -= 1
        }
        if (left == 0) {
            break
        }
        while (steps != k) {
            cur = (cur + 1) % n;
            if (!u[cur]) {
                steps += 1
            }
        }
    }
    println(ans)
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