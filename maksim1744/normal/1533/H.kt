/*
    author:  Maksim1744
    created: 29.06.2021 18:20:39
*/

fun popcount(x: Int): Int {
    var ans = 0
    for (j in 0 until 10) {
        if (x.shr(j).and(1) != 0) {
            ans += 1
        }
    }
    return ans
}

fun main() {
    var (n, m) = readLine()!!.split(' ').map{ it.toInt() }
    var v = ArrayList<String>()
    repeat(n) {
        var s = readLine()!!
        v.add(s)
    }

    var res = LongArray(32) {0L}

    for (mask in 0 until 32) {
        var lets = ArrayList<Boolean>()
        for (i in 0..4) {
            if ((mask.shr(i)).and(1) != 0) {
                lets.add(true);
            } else {
                lets.add(false);
            }
        }
        var cur = ArrayList<ArrayList<Int>>()
        for (i in 0 until n) {
            var ln = ArrayList<Int>()
            for (j in 0 until m) {
                if (lets[v[i][j] - 'A']) {
                    ln.add(1)
                } else {
                    ln.add(0)
                }
            }
            cur.add(ln)
        }
        var ans = 0L

        var curh = ArrayList<Int>()
        repeat(m) {
            curh.add(0)
        }

        for (i in 0 until n) {
            for (j in 0 until m) {
                curh[j] += 1
                if (cur[i][j] == 1) {
                    curh[j] = 0
                }
            }

            var tol = IntArray(m) { -1 }
            var tor = IntArray(m) { m }

            var st = ArrayList<Int>()
            for (j in 0 until m) {
                while (st.size != 0 && curh[st[st.size - 1]] > curh[j]) {
                    st.removeAt(st.size - 1)
                }
                if (st.size != 0) {
                    tol[j] = st[st.size - 1]
                }
                st.add(j)
            }
            st = ArrayList<Int>()
            for (j in m-1 downTo 0) {
                while (st.size != 0 && curh[st[st.size - 1]] >= curh[j]) {
                    st.removeAt(st.size - 1)
                }
                if (st.size != 0) {
                    tor[j] = st[st.size - 1]
                }
                st.add(j)
            }

            for (j in 0 until m) {
                var L = (j - tol[j]).toLong()
                var R = (tor[j] - j).toLong()
                var H = curh[j]
                ans += L * R * H
            }
        }

        res[mask.xor(31)] = ans
    }

    for (i in 0 until 32) {
        for (j in 0 until i) {
            if (j.and(i) == j) {
                res[i] -= res[j]
            }
        }
    }

    var ans = LongArray(6) {0L}
    for (i in 0 until 32) {
        ans[popcount(i)] += res[i]
    }
    for (i in 1..5) {
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