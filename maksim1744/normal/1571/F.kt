/*
    author:  Maksim1744
    created: 07.10.2021 18:17:38
*/

fun test_case() {
    var (n, m) = readLine()!!.split(' ').map{ it.toInt() }
    var total = 0
    var lens = ArrayList<Int>()
    var len_inds = ArrayList<Int>()
    var longs = ArrayList<Int>()
    var len_longs = ArrayList<Int>()
    for (i in 0..n-1) {
        var (k, t) = readLine()!!.split(' ').map{ it.toInt() }
        if (t == 1 && k != 1) {
            longs.add(i)
            len_longs.add(k)
            m -= k
        } else {
            len_inds.add(i)
            lens.add(k)
            total += k
        }
    }

    if (total > m) {
        println(-1)
        return
    }
    // print("lens: ")
    // for (k in lens) {
    //     print("$k ")
    // }
    // println()
    // println("total: $total")
    // println("m: $m")

    var can = ArrayList<ArrayList<Int>>()
    for (j in 0..lens.size) {
        var ccan = ArrayList<Int>()
        for (i in 0..m) {
            ccan.add(0)
        }
        can.add(ccan)
    }
    can[0][0] = 1
    var sm = 0
    for (j in 0..lens.size - 1) {
        var k = lens[j]
        sm += k
        for (i in 0..can[j].size-1) {
            can[j + 1][i] = can[j][i]
        }
        for (i in can[j + 1].size - 1 downTo k) {
            if (can[j + 1][i - k] == 1) {
                can[j + 1][i] = 1
            }
        }
    }
    // println("can:")
    // for (u in can) {
    //     for (v in u) {
    //         print(v)
    //     }
    //     println()
    // }
    var cans1 = (m + 1) / 2
    var cans2 = m / 2
    for (s1 in 0..can[0].size - 1) {
        if (s1 > cans1) {
            break
        }
        if (sm - s1 > cans2) {
            continue
        }
        if (can[can.size-1][s1] == 1) {
            var ans = ArrayList<Int>()
            for (i in 0..n-1) {
                ans.add(-1)
            }
            var last = 1
            for (i in 0..len_longs.size-1) {
                ans[longs[i]] = last
                last += len_longs[i]
            }
            var last1 = last
            var last2 = last + 1

            var ind = can.size - 1
            var curs = s1
            while (ind != 0) {
                var ii = len_inds[ind - 1]
                if (can[ind - 1][curs] == 1) {
                    ans[ii] = last2
                    last2 += lens[ind - 1] * 2
                } else {
                    ans[ii] = last1
                    last1 += lens[ind - 1] * 2
                    curs -= lens[ind - 1]
                }
                ind -= 1
            }

            for (k in ans) {
                print("$k ")
            }
            println()
            return
        }
    }
    println(-1)
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
    var t = 1
    for (test in 1..t) {
        test_case()
    }
}