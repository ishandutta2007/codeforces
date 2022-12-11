import java.lang.Integer.max
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
fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }
fun add(a: Int, b: Int) = (a+b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a-b+MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong()*b)%MOD).toInt()
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)

fun example() {
    println(String.format("%.8f", 5.25)) // print to 8 decimals
    val arr2D = Array<IntArray>(5,{IntArray(5,{5})})
    var (x,y) = arrayOf(3,2) // or rInts(2)
    when (x) { //  switch, can be used as expression
        0,1 -> println("x <= 1")
        2 -> println("x == 2") // Note the block
        else -> { println("x is neither 1 nor 2") }
    }
    x = y.also { y = x } // swap x and y
    println("${maxOf(x+2,y)}") // (x,y)=(4,3) -> 4
    val h = HashMap<String,Int>()
    val s = "ababa"
    for (i in 0..s.length-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w,{0})
        h[w] = c+1
    }
    for ((a,b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long,Int>>(){x,y ->
        x.first.compareTo(y.first)} // or compareBy{it.first}
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
        x.first.compareTo(y.first)}) // or sortBy{it.first}
    val list = arrayListOf('a','b','c','d','e')
    println(list.binarySearch('d')) // 3
    list.remove('d')
    val actualInsertPoint = -(list.binarySearch('d')+1) // 3
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
lateinit var t: Array<Int>
fun build(v:Int,vl:Int,vr:Int)
{
    if (vl==vr)
    {
        t[v]=0
        return
    }
    val mid=(vl+vr)/2
    build(2*v+1,vl,mid)
    build(2*v+2,mid+1,vr)
    t[v]=max(t[2*v+1],t[2*v+2])
}
fun update(v:Int,vl:Int,vr:Int,pos:Int,x:Int)
{
    if (vl==vr)
    {
        t[v]=max(t[v],x)
        return
    }
    val mid=(vl+vr)/2
    if (pos<=mid)
        update(2*v+1,vl,mid,pos,x)
    else
        update(2*v+2,mid+1,vr,pos,x)
    t[v]=max(t[2*v+1],t[2*v+2])
}
fun query(v:Int,vl:Int,vr:Int,l:Int,r:Int):Int
{
    if (vl>r||vr<l)
        return 0
    if (l<=vl&&vr<=r)
        return t[v]
    val mid=(vl+vr)/2
    return max(query(2*v+1,vl,mid,l,r),query(2*v+2,mid+1,vr,l,r))
}
fun solve()
{
    var n=readInt()
    t=Array<Int>(4*(n+1)){0}
    build(0,0,n)
    var a=readInts()
    var ans=1
    var g = Array(n) { ArrayList<Int>() }
    for (i in 0 until n){
        g[a[i]-1].add(i)
    }
    var b=mutableListOf<Pair<Int,Int>>()
    for (i in 0 until n)
    {
        if (g[i].size!=2)
            continue
        b.add(Pair(g[i][0],g[i][1]))
    }
    val was=n
    n=b.size
    if (n==0)
    {
        println(1)
        return
    }
    b.sortBy { it.first }
//    println(b)
    for (i in 0 until n){
        var x=b[i].second
        var f=query(0,0,was,x+1,was)
        var t=2+f
        if (b[i].first+1!=b[i].second)
            ans=max(ans,t+1)
        else
            ans=max(ans,t)
//        println(t)
        update(0,0,was,x,t)
    }
    println(ans)
}
fun main(args: Array<String>) {
    var t=1
    t=readInt()
    while (t-->0)
        solve()
}