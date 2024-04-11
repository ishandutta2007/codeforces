import java.lang.Long.min

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
lateinit var par: Array<Int>
lateinit var ranks: Array<Int>
lateinit var v: Array<Long>
fun make_set(s: Int, x: Long)
{
    par[s]=s
    v[s]=x
    ranks[s]=0
}
fun find_set(s: Int):Int{
    if (s==par[s])
        return s
    val x=find_set(par[s])
    par[s]=x
    return x
}
fun union_sets(uu: Int,vv: Int){
    var u=find_set(uu)
    var vvv=find_set(vv)
    if (u!=vvv)
    {
        if (ranks[u]<ranks[vvv])
        {
            val g=u
            u=vvv
            vvv=g
        }
        par[vvv]=u
        v[u]=min(v[u],v[vvv])
        if (ranks[u]==ranks[vvv])
            ranks[u]++
    }
}
fun main(args: Array<String>) {
    var (n,m)=readInts()
    par=Array<Int>(n){0}
    v=Array<Long>(n){0L}
    ranks=Array<Int>(n){0}
    val a=readLongs()
    for (i in 0 until n)
        make_set(i,a[i])
    val c=Array<Pair<Long,Pair<Int,Int>>>(m){Pair<Long,Pair<Int,Int>>(0L,Pair<Int,Int>(0,0))}
    for (i in 0 until m)
    {
        var (y,z,x)=readLongs()
        y--
        z--
        c[i]=Pair<Long,Pair<Int,Int>>(x,Pair<Int,Int>(y.toInt(),z.toInt()))
    }
    c.sortWith(compareBy { it.first })
    var now=0
    val s=sortedSetOf((1L*a[0]*n))
    for (i in 1 until n)
        s.add(1L*a[i]*n+1L*i)
    var ans=0L
    while (s.size > 1)
    {
        while (now<m&&find_set(c[now].second.first)==find_set(c[now].second.second))
            now++
        var x=Pair<Long,Int>(0L,0)
        var y=Pair<Long,Int>(0L,0)
        var cnt=0
        for (xx in s)
        {
            cnt++
            if (cnt==3)
                break
            if (cnt==1)
                x= Pair<Long,Int>(xx/n, (xx%n).toInt())
            else
                y=Pair<Long,Int>(xx/n, (xx%n).toInt())
        }
        if (now==m||(x.first+y.first<c[now].first))
        {
            ans+=x.first+y.first
            s.remove(x.first*n+x.second)
            s.remove(y.first*n+y.second)
            union_sets(x.second,y.second)
            val g=find_set(x.second)
            s.add(v[g]*n+g)
        }
        else
        {
            ans+=c[now].first
            var u=find_set(c[now].second.first)
            var vv=find_set(c[now].second.second)
            s.remove(v[u]*n+u)
            s.remove(v[vv]*n+vv)
            union_sets(u,vv)
            val g=find_set(u)
            s.add(v[g]*n+g)
            now++
        }
    }
    println(ans)
}