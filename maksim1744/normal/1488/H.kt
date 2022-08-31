/*
    author:  Maksim1744
    created: 09.03.2021 19:06:26
*/

var mod = 998244353;

fun main() {
    var (n, q) = readLine()!!.split(' ').map{ it.toInt() }
    var a = readLine()!!.split(' ').map{ it.toInt() }.toMutableList()
    var N = 1
    while (N < n) {
        N *= 2
    }
    for (i in 0..n-2) {
        a[i] = 1 - a[i]
    }
    var tree = ArrayList<Array<Array<Int>>>()
    for (ii in 1..N * 2 + 5) {
        var mt = Array(4) {Array(4) {0} }
        for (i in 1..4) {
            // var aa = intArrayOf(0, 0, 0, 0)
            // for (j in 1..4) {
            //     aa.add(0)
            // }
            // aa[i - 1] = 1
            // mt.add(aa)
            mt[i - 1][i - 1] = 1
        }
        tree.add(mt)
    }
    // println("${tree.toString()}")
    N -= 1
    fun mult(c: Array<Array<Int>>, a: Array<Array<Int>>, b: Array<Array<Int>>) {
        for (i in 0..3) {
            for (j in 0..3) {
                c[i][j] = 0
            }
        }
        for (i in 0..a.size - 1) {
            for (j in 0..a[0].size - 1) {
                for (k in 0..b[0].size - 1) {
                    c[i][k] = ((c[i][k] + a[i][j].toLong() * b[j][k].toLong() % mod) % mod).toInt()
                }
            }
        }
    }
    fun upd_mat(i: Int) {
        if (i < 0) {
            return
        }
        if (i >= n - 1) {
            return
        }
        if ((i + 1 < a.size && a[i] != a[i + 1]) || (a[i] == 0 && i == n - 2)) {
            if (a[i] == 1) {
                tree[N + i][0][0] = 0
                tree[N + i][0][1] = 0
                tree[N + i][0][2] = 0
                tree[N + i][0][3] = 0

                tree[N + i][1][0] = 1
                tree[N + i][1][1] = 0
                tree[N + i][1][2] = 0
                tree[N + i][1][3] = 0

                tree[N + i][2][0] = 1
                tree[N + i][2][1] = 1
                tree[N + i][2][2] = 0
                tree[N + i][2][3] = 0

                tree[N + i][3][0] = 1
                tree[N + i][3][1] = 1
                tree[N + i][3][2] = 1
                tree[N + i][3][3] = 0
            } else {
                tree[N + i][0][0] = 0
                tree[N + i][0][1] = 1
                tree[N + i][0][2] = 1
                tree[N + i][0][3] = 1

                tree[N + i][1][0] = 0
                tree[N + i][1][1] = 0
                tree[N + i][1][2] = 1
                tree[N + i][1][3] = 1

                tree[N + i][2][0] = 0
                tree[N + i][2][1] = 0
                tree[N + i][2][2] = 0
                tree[N + i][2][3] = 1

                tree[N + i][3][0] = 0
                tree[N + i][3][1] = 0
                tree[N + i][3][2] = 0
                tree[N + i][3][3] = 0
            }
        } else {
            if (a[i] == 1) {
                tree[N + i][0][0] = 1
                tree[N + i][0][1] = 0
                tree[N + i][0][2] = 0
                tree[N + i][0][3] = 0

                tree[N + i][1][0] = 1
                tree[N + i][1][1] = 1
                tree[N + i][1][2] = 0
                tree[N + i][1][3] = 0

                tree[N + i][2][0] = 1
                tree[N + i][2][1] = 1
                tree[N + i][2][2] = 1
                tree[N + i][2][3] = 0

                tree[N + i][3][0] = 1
                tree[N + i][3][1] = 1
                tree[N + i][3][2] = 1
                tree[N + i][3][3] = 1
            } else {
                tree[N + i][0][0] = 1
                tree[N + i][0][1] = 1
                tree[N + i][0][2] = 1
                tree[N + i][0][3] = 1

                tree[N + i][1][0] = 0
                tree[N + i][1][1] = 1
                tree[N + i][1][2] = 1
                tree[N + i][1][3] = 1

                tree[N + i][2][0] = 0
                tree[N + i][2][1] = 0
                tree[N + i][2][2] = 1
                tree[N + i][2][3] = 1

                tree[N + i][3][0] = 0
                tree[N + i][3][1] = 0
                tree[N + i][3][2] = 0
                tree[N + i][3][3] = 1
            }
        }
    }
    for (i in 0..n-2) {
        upd_mat(i)
    }
    for (i in N-1 downTo 0) {
        mult(tree[i], tree[i * 2 + 1], tree[i * 2 + 2])
    }
    fun go_up(ii: Int) {
        var i = ii + N
        while (i != 0) {
            i = (i - 1) / 2
            mult(tree[i], tree[i * 2 + 1], tree[i * 2 + 2])
        }
    }
    // println("n = $N")
    // println("${tree.toString()}")
    for (que in 1..q) {
        var ind = readLine()!!.toInt()
        ind -= 1
        a[ind] = 1 - a[ind]
        upd_mat(ind)
        upd_mat(ind - 1)
        // push
        go_up(ind)
        go_up(ind - 1)
        // for (i in N-1 downTo 0) {
        //     tree[i] = mult(tree[i * 2 + 1], tree[i * 2 + 2])
        // }
        // println("${tree.toString()}")
        var ans = 0.toLong()
        for (i in 0..3) {
            for (j in 0..3) {
                ans += tree[0][i][j]
            }
        }
        println("${ans % mod}")
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