/*
    author:  Maksim1744
    created: 09.03.2021 18:43:58
*/

fun main() {
    var n = readLine()!!.toInt()
    var ans = ArrayList<Int>()
    for (i in 0..n) {
        ans.add(-1)
    }

    var divs = ArrayList<ArrayList<Int>>()
    for (i in 0..n) {
        divs.add(ArrayList<Int>())
    }
    for (i in 1..n) {
        for (j in 2..n) {
            if (i * j > n) {
                break;
            }
            divs[i * j].add(i)
        }
    }

    var cost = ArrayList<Int>()
    for (i in 0..n) {
        cost.add(0)
    }
    for (i in 1..n) {
        var j = i * 2;
        while (j <= n) {
            cost[i] += 1
            j += i
        }
    }

    var ss = sortedSetOf(0.toLong())
    fun tol(p: Pair<Int, Int>) : Long {
        return (p.first.toLong() + 500000000) * 1000000000.toLong() + p.second.toLong()
    }
    fun froml(l : Long) : Pair<Int, Int> {
        return Pair((l / 1000000000.toLong() - 500000000).toInt(), (l % 1000000000).toInt())
    }
    ss.remove(0)
    for (i in 1..n) {
        ss.add(tol(Pair(cost[i], i)))
    }

    var cur = 0
    var taken = ArrayList<Boolean>()
    for (i in 0..n+1) {
        taken.add(false)
    }

    for (k in 1..n) {
        var x = froml(ss.last())
        ss.remove(tol(x))
        cur += x.first
        var num = x.second
        var y = num * 2
        taken[num] = true
        while (y <= n) {
            if (!taken[y]) {
                ss.remove(tol(Pair(cost[y], y)))
            }
            cost[y] -= 1
            if (!taken[y]) {
                ss.add(tol(Pair(cost[y], y)))
            }
            y += num
        }
        ans[n - k] = cur
    }

    ans[n] = 0

    for (i in 1..n) {
        print("${ans[i]} ")
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