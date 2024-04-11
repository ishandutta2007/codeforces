/*
    author:  Maksim1744
    created: 09.03.2021 18:23:58
*/

fun main() {
    readLine()!!.toInt()
    var a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var q = readLine()!!.toInt()
    var que = ArrayList<Pair<Pair<Int, Int>, Int>>()
    for (i in 0..q-1) {
        var (x, b) = readLine()!!.split(' ').map{ it.toInt() }
        x -= 1
        b -= 1
        que.add(Pair(Pair(x, b), i))
    }
    que.sortWith(compareBy({it.first.second}))
    var ind = 0
    var ans = ArrayList<Long>()
    for (i in 0..q-1) {
        ans.add(-1);
    }
    var s = ArrayList<Pair<Int, Pair<Int, Long>>>()
    s.add(Pair(1000000000, Pair(0, 0)))
    for (qq in que) {
        var l = qq.first.first
        var r = qq.first.second
        var i = qq.second
        while (ind <= r) {
            while (s[s.size - 1].first <= a[ind]) {
                // var c = s[s.size - 1].second.first - s[s.size - 2].second.first
                s.removeAt(s.size - 1)
            }
            var cur_cnt = ind + 1
            s.add(Pair(a[ind], Pair(cur_cnt, s[s.size - 1].second.second + (cur_cnt - s[s.size - 1].second.first).toLong() * a[ind].toLong())))
            ind += 1
        }
        // ask
        var L = 0
        var R = s.size.toInt()
        while (R - L > 1) {
            var C = (L + R) / 2
            if (s[C].second.first > l) {
                R = C
            } else {
                L = C
            }
        }
        ans[i] = s[s.size - 1].second.second - s[L].second.second - (l - s[L].second.first).toLong() * s[R].first.toLong()
    }
    for (k in ans) {
        print("$k ")
    }
    println()
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