/*
    author:  Maksim1744
    created: 29.06.2021 19:11:22
*/

fun main() {
    var n = readLine()!!.toInt()
    var N = 500010
    // var N = 500

    var byy = ArrayList<ArrayList<Int>>()
    var byy1 = ArrayList<ArrayList<Int>>()
    var byy1u = ArrayList<ArrayList<Boolean>>()
    var byy2 = ArrayList<ArrayList<Int>>()
    var byy2u = ArrayList<ArrayList<Boolean>>()
    repeat(N) {
        var s = ArrayList<Int>()
        byy.add(s)
    }
    repeat(N) {
        var s = ArrayList<Int>()
        byy1.add(s)

        var s2 = ArrayList<Boolean>()
        byy1u.add(s2)
    }
    repeat(N) {
        var s = ArrayList<Int>()
        byy2.add(s)

        var s2 = ArrayList<Boolean>()
        byy2u.add(s2)
    }

    repeat(n) {
        var (x, y) = readLine()!!.split(' ').map{ it.toInt() }
        y = y + 4
        x = -x
        byy[y].add(x)
        if (y % 2 == 0) {
            byy1[y].add(x)
        } else {
            byy2[y].add(x)
        }
    }

    for (i in 0 until N) {
        byy[i].sort()
        byy[i].reverse()
        byy1[i].sort()
        byy1[i].reverse()
        byy2[i].sort()
        byy2[i].reverse()

        for (j in 0 until byy1[i].size) {
            byy1u[i].add(false)
        }
        for (j in 0 until byy2[i].size) {
            byy2u[i].add(false)
        }
    }

    var sz = n
    for (i in 0 until N) {
        if (i % 2 == 0) {
            var v1 = ArrayList<Int>()
            var i1 = 0
            var v2 = ArrayList<Int>()
            var i2 = 0
            for (x in byy[i]) {
                while (i1 < byy2[i - 1].size && byy2[i - 1][i1] > x) {
                    if (!byy2u[i - 1][i1]) {
                        v1.add(i1)
                    }
                    i1 += 1
                }
                if (v1.size != 0) {
                    var ind = v1[v1.size - 1]
                    v1.removeAt(v1.size - 1)
                    byy2u[i - 1][ind] = true
                    sz -= 1
                    continue
                }

                while (i2 < byy2[i + 1].size && byy2[i + 1][i2] > x) {
                    if (!byy2u[i + 1][i2]) {
                        v2.add(i2)
                    }
                    i2 += 1
                }
                if (v2.size != 0) {
                    var ind = v2[v2.size - 1]
                    v2.removeAt(v2.size - 1)
                    byy2u[i + 1][ind] = true
                    sz -= 1
                    continue
                }
            }
        }
    }

    for (i in 0 until N) {
        if (i % 2 == 1) {
            var v1 = ArrayList<Int>()
            var i1 = 0
            var v2 = ArrayList<Int>()
            var i2 = 0
            for (x in byy[i]) {
                while (i1 < byy1[i - 1].size && byy1[i - 1][i1] > x) {
                    if (!byy1u[i - 1][i1]) {
                        v1.add(i1)
                    }
                    i1 += 1
                }
                if (v1.size != 0) {
                    var ind = v1[v1.size - 1]
                    v1.removeAt(v1.size - 1)
                    byy1u[i - 1][ind] = true
                    sz -= 1
                    continue
                }

                while (i2 < byy1[i + 1].size && byy1[i + 1][i2] > x) {
                    if (!byy1u[i + 1][i2]) {
                        v2.add(i2)
                    }
                    i2 += 1
                }
                if (v2.size != 0) {
                    var ind = v2[v2.size - 1]
                    v2.removeAt(v2.size - 1)
                    byy1u[i + 1][ind] = true
                    sz -= 1
                    continue
                }
            }
        }
    }
    println(sz)
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