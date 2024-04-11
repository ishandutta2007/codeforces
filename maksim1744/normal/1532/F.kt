/*
    author:  Maksim1744
    created: 22.06.2021 19:33:07
*/

fun main() {
    var n = readLine()!!.toInt()
    var a = ArrayList<String>()
    var b = ArrayList<ArrayList<Int>>()
    for (i in 1..n+1) {
        var x = ArrayList<Int>()
        b.add(x)
    }
    for (i in 0..n*2-3) {
        var s = readLine()!!
        a.add(s)
        b[s.length].add(i)
    }

    for (it in 0..1) {
        var s = StringBuilder("")
        if (it == 0) {
            s.append(a[b[n - 1][0]][0])
            s.append(a[b[n - 1][1]])
        } else {
            s.append(a[b[n - 1][1]][0])
            s.append(a[b[n - 1][0]])
        }
        var ans = StringBuilder("")
        for (i in 0..a.size-1) {
            ans.append('.')
        }

        var ok = true
        for (ln in 1..n-1) {
            if (a[b[ln][0]] == s.substring(0, ln) && a[b[ln][1]] == s.substring(n - ln, n)) {
                ans[b[ln][0]] = 'P'
                ans[b[ln][1]] = 'S'
            } else if (a[b[ln][1]] == s.substring(0, ln) && a[b[ln][0]] == s.substring(n - ln, n)) {
                ans[b[ln][1]] = 'P'
                ans[b[ln][0]] = 'S'
            } else {
                ok = false
            }
        }
        if (!ok) {
            continue
        }
        println(ans)
        return;
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