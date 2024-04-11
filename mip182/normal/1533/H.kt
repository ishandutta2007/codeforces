import java.util.*
import kotlin.Comparator
import kotlin.collections.HashMap

// Thanks BenQ!
/* sorting
 * 1 (ok)
	val a = nextLongs().sorted() // a is mutable list
 * 2 (ok)
	val a = arrayListOf<Long>() // or ArrayList<Long>()
	a.addAll(nextLongs())
	a.sort()
 * 3 (ok)
	val A = nextLongs()
	val a = Array<Long>(n,{0})
	for (i in 0..n-1) a[i] = A[i]
	a.sort()
 * 4 (ok)
	val a = ArrayList(nextLongs())
	a.sort()
 * 5 (NOT ok, quicksort)
	val a = LongArray(N) // or nextLongs().toLongArray()
	Arrays.sort(a)
 */
/* 2D array
 * val ori = Array(n, {IntArray(n)})
 * val ori = arrayOf(
	intArrayOf(8, 9, 1, 13),
	intArrayOf(3, 12, 7, 5),
	intArrayOf(0, 2, 4, 11),
	intArrayOf(6, 10, 15, 14)
	)
 */
/* printing variables:
 * println("${l+1} and $r")
 * print d to 8 decimal places: String.format("%.8g%n", d)
 * try to print one stringbuilder instead of multiple prints
 */
/* comparing pairs
	val pq = PriorityQueue<Pair<Long,Int>>({x,y -> x.first.compareTo(y.first)})
										~ (compareBy {it.first})
	val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
	val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y -> x.first.compareTo(y.first)})
	sortBy
 */
/* hashmap
	val h = HashMap<String,Int>()
	for (i in 0..n-2) {
		val w = s.substring(i,i+2)
		val c = h.getOrElse(w){0}
		h.put(w,c+1)
	}
 */
/* basically switch, can be used as expression
	when (x) {
		0,1 -> print("x <= 1")
		2 -> print("x == 2")
		else -> { // Note the block
			print("x is neither 1 nor 2")
		}
	}
*/
// swap : a = b.also { b = a }
// arraylist remove element at index: removeAt, not remove ...
// lower bound: use .binarySearch()
//----------------------------------------------------------------------------------
//fun dfs(a: Int, b: Int) {
//    if (cur == k) return
//    ans[a] = true
//    if (b != 0) {
//        cur ++
//        deg[a] ++
//        if (deg[b] == 1) cur --
//        deg[b] ++
//        if (deg[b] == 1) cur ++
//    }
//    for (i in adj[a]) if (i != b) {
//        dfs(i,a)
//    }
//}
//  
//----------------------------------------------------------------------------------
// fun go(a: Int) : Int {
//    return a
//}
//----------------------------------------------------------------------------------
// Thanks BenQ xD
const val MOD = 998244353
const val INFLL = (1e18).toLong()
const val INF = (1e9).toInt()
const val SZ = 1 shl 17
fun YN(b: Boolean): String {
    return if (b) "YES" else "NO"
}

fun add(a: Int, b: Int) = (a + b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()
fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)

fun example() {
    println(String.format("%.8f", 5.25)) // print to 8 decimals
    val arr2D = Array<IntArray>(5, { IntArray(5, { 5 }) })
    var (x, y) = arrayOf(3, 2) // or rInts(2)
    when (x) { //  switch, can be used as expression
        0, 1 -> println("x <= 1")
        2 -> println("x == 2") // Note the block
        else -> {
            println("x is neither 1 nor 2")
        }
    }
    x = y.also { y = x } // swap x and y
    println("${maxOf(x + 2, y)}") // (x,y)=(4,3) -> 4
    val h = HashMap<String, Int>()
    val s = "ababa"
    for (i in 0..s.length - 2) {
        val w = s.substring(i, i + 2)
        val c = h.getOrElse(w, { 0 })
        h[w] = c + 1
    }
    for ((a, b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long, Int>>() { x, y ->
        x.first.compareTo(y.first)
    } // or compareBy{it.first}
    val A = arrayListOf(Pair(1, 3), Pair(3, 2), Pair(2, 3))
    val B = A.sortedWith(Comparator<Pair<Int, Int>> { x, y ->
        x.first.compareTo(y.first)
    }) // or sortBy{it.first}
    val list = arrayListOf('a', 'b', 'c', 'd', 'e')
    println(list.binarySearch('d')) // 3
    list.remove('d')
    val actualInsertPoint = -(list.binarySearch('d') + 1) // 3
    list.add(actualInsertPoint, 'd') // [a,b,c,d,e]
    list.removeAt(1) // remove at index -> [a,c,d,e]
}

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

// var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })  ,   
// ArrayList - ,   
// Array<Int>(n){0} - ,     
// ArrayList< ArrayList<Int> >() - 
// Array(n, { ArrayList<Pair<Int, Int>>() }) -  ,   
// var g = Array(n) { ArrayList<Int>() } -  
// val , var 
// ---------------------------------------------------
// var cnt = IntArray(MAX)
// var r = readInts()
//    for (x in r) cnt[x]++
//    3 (ok)
//val A = nextLongs()
//val a = Array<Long>(n,{0})
//for (i in 0..n-1) a[i] = A[i]
//  ArrayList  
//a.sort()
// for (x in a),  a - , 
//----------------------------------------------------
//   var
// mutableListOf<Int>() -         
//     - $x,$a
// var b = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)}) - quick initialize
// b.sortWith(compareBy({it.first}, {it.second})) - sort pairs
//var A: Array<Int> = TODO() , initialize global array
// use it for custom comparator
// sort , sorted     
fun solve() {
    var (n, m) = readInts()
    var ss = Array<String>(n) { "" }
    for (i in 0 until n) {
        ss[i] = readLine().toString()
    }
    var s = Array<Array<Int>>(n) { Array<Int>(m) { 0 } }
    for (i in 0 until n) {
        for (j in 0 until m) {
            s[i][j] = (ss[i][j] - 'A').toInt()
        }
    }
    var dp = Array<Long>(32) { 0 }
    var st = Array<Pair<Int, Int>>(m + 1) { Pair<Int, Int>(0, 0) }
    for (mask in 1 until 32) {
        var h = Array<Int>(m) { 0 }
        var cur = 0L
        for (i in 0 until n) {
            for (j in 0 until m) {
                if ((mask shr s[i][j]) % 2 == 1) {
                    h[j]++
                } else
                    h[j] = 0
            }
            var lef = Array<Int>(m) { 0 }
//            var st = Stack<Pair<Int, Int>>()
//            st.add(Pair<Int, Int>(-1, -1))
            var curr = 0
            for (j in 0 until m) {
                var ha = -1
                while (curr > 0) {
                    var b = st[curr]
                    if (b.first > h[j])
                        curr--
                    else {
                        ha = b.second
                        break
                    }
                }
                lef[j] = ha
                curr++
                st[curr] = (Pair<Int, Int>(h[j], j))
            }
            curr = 0
//            var rig = Array<Int>(m) { 0 }
//            st.add(Pair<Int, Int>(-1, m))
//            var j = m - 1
//            while (j >= 0) {
//                while (st.size > 0) {
//                    var b = st.peek()
//                    if (b.first >= h[j])
//                        st.pop()
//                    else {
//                        rig[j] = b.second
//                        break
//                    }
//                }
//                st.push(Pair<Int, Int>(h[j], j))
//                j--
//            }
//            j = 0
//            while (j < m) {
//                dp[mask] = dp[mask] + (j - lef[j]) * (rig[j] - j) * h[j]
//                j++
//            }
            var j = m - 1
            while (j >= 0) {
                var ha = m
                while (curr > 0) {
                    var b = st[curr]
                    if (b.first >= h[j])
                        curr--
                    else {
                        ha = b.second
                        break
                    }
                }
                curr++
                st[curr] = (Pair<Int, Int>(h[j], j))
                cur += (j - lef[j]) * (ha - j) * h[j]
                j--
            }
        }
//        println(cur)
        dp[mask] = cur
    }
    var ans = Array<Long>(32) { 0 }
    for (mask in 1 until 32) {
        ans[mask] = dp[mask]
        var sub_mask = mask
        while (sub_mask > 0) {
            ans[mask] -= ans[sub_mask]
            sub_mask = ((sub_mask - 1) and mask)
        }
        ans[mask] += dp[mask]
    }
    var true_ans = Array<Long>(6) { 0 }
    for (mask in 1 until 32) {
        var x = mask
        var cnt = 0
        for (j in 0 until 5) {
            if (x % 2 == 1)
                cnt++
            x /= 2
        }
        true_ans[cnt] += ans[mask]
    }
    for (i in 1 until 6)
        print("${true_ans[i]} ")

}

fun main(args: Array<String>) {
    var t = 1
//    t=readInt()
    while (t-- > 0)
        solve()
}