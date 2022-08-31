/*
    author:  Maksim1744
    created: 22.06.2021 19:24:49
*/

fun main() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var mx1 = 0
    var mx2 = 0
    var sm = 0.toLong()
    for (k in a) {
        sm += k
        if (k >= mx1) {
            mx2 = mx1
            mx1 = k
        } else if (k > mx2) {
            mx2 = k
        }
    }

    var ans = ArrayList<Int>()
    for (i in 0..n-1) {
        var curmx = mx1
        if (a[i] == mx1) {
            curmx = mx2
        }
        var cursm = sm - a[i]
        if (cursm == (curmx * 2).toLong()) {
            ans.add(i + 1)
        }
    }
    println(ans.size)
    for (k in ans) {
        print("$k ")
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