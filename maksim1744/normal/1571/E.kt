/*
    author:  Maksim1744
    created: 07.10.2021 18:07:39
*/

fun test_case() {
    var n = readLine()!!.toInt()
    var s = readLine()!!
    var t = readLine()!!
    var res = StringBuilder("")
    for (i in 0..n-1) {
        res.append('?')
    }

    for (i in 0..n-4) {
        if (t[i] == '0') {
            continue
        }
        res[i] = '('
        res[i + 3] = ')'
    }
    for (i in 0..n-4) {
        if (t[i] == '0') {
            continue
        }
        if (res[i + 1] == '(') {
            res[i + 2] = ')'
        } else if (res[i + 1] == ')') {
            res[i + 2] = '('
        } else if (res[i + 2] == ')') {
            res[i + 1] = '('
        } else if (res[i + 2] == '(') {
            res[i + 1] = ')'
        }
    }
    var ok = true
    var ans = 0
    for (i in 0..n-4) {
        if (t[i] == '0') {
            continue
        }
        if (res[i] != '(') {
            ok = false
        }
        if (res[i + 3] != ')') {
            ok = false
        }
        if (res[i + 1] == res[i + 2]) {
            if (res[i + 1] == '?') {
                if (s[i + 1] != s[i + 2]) {
                    ans += 0
                } else {
                    ans += 1
                }
            } else {
                ok = false
            }
        }
    }

    if (!ok) {
        println(-1)
        return
    }

    for (i in 0..n-1) {
        if (res[i] != '?') {
            if (res[i] != s[i]) {
                ans += 1
            }
        }
    }

    println(ans)
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