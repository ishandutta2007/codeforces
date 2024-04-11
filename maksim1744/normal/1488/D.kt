/*
    author:  Maksim1744
    created: 09.03.2021 17:49:28
*/

fun test_case() {
    var (n, s) = readLine()!!.split(' ').map{ it.toLong() }
    var L = s / n - 5;
    while (L * n < s) {
        L += 1;
    }
    var R = 3.toLong();
    for (i in 1..18) {
        R *= 10;
    }
    while (R - L > 1) {
        var C = (L + R) / 2;
        var cur = C;
        var have = 0.toLong();
        for (i in 1..n) {
            if (cur == 1.toLong()) {
                have += n - i + 1;
                break;
            }
            have += cur;
            if (have > s) {
                break;
            }
            cur = (cur + 1) / 2;
        }
        if (have > s) {
            R = C;
        } else {
            L = C;
        }
    }
    println("$L")
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