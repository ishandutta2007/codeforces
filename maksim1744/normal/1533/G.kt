/*
    author:  Maksim1744
    created: 29.06.2021 18:07:36
*/

fun dfs(x: Int, y: Int, a: ArrayList<ArrayList<Int>>, res: ArrayList<Int>, u: ArrayList<ArrayList<Int>>, n: Int, m: Int) {
    u[x][y] = 1
    res.add(a[x][y])
    if (x - 1 >= 0 && u[x - 1][y] == 0 && a[x - 1][y] != 0) {
        dfs(x - 1, y, a, res, u, n, m)
        res.add(a[x][y])
    }
    if (x + 1 < n && u[x + 1][y] == 0 && a[x + 1][y] != 0) {
        dfs(x + 1, y, a, res, u, n, m)
        res.add(a[x][y])
    }
    if (y - 1 >= 0 && u[x][y - 1] == 0 && a[x][y - 1] != 0) {
        dfs(x, y - 1, a, res, u, n, m)
        res.add(a[x][y])
    }
    if (y + 1 < m && u[x][y + 1] == 0 && a[x][y + 1] != 0) {
        dfs(x, y + 1, a, res, u, n, m)
        res.add(a[x][y])
    }
}

fun test_case() {
    var (n, m) = readLine()!!.split(' ').map{ it.toInt() }

    var a = ArrayList<ArrayList<Int>>()
    var u = ArrayList<ArrayList<Int>>()
    repeat(n) {
        var aa = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
        var ab = ArrayList<Int>()
        var uu = ArrayList<Int>()
        for (x in aa) {
            ab.add(x)
            uu.add(0)
        }
        u.add(uu)
        a.add(ab)
    }

    var res = ArrayList<Int>()

    var found = false
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (a[i][j] != 0) {
                found = true
                dfs(i, j, a, res, u, n, m)
                break
            }
        }
        if (found) {
            break
        }
    }

    var need = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (a[i][j] != 0) {
                need += 1
            }
        }
    }

    var have = (res.size + 1) / 2
    if (need != have) {
        println(-1)
        return
    }

    println("$need $need")
    for (i in 0 until need) {
        for (j in 0 until need) {
            print("${res[i + j]} ")
        }
        println()
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