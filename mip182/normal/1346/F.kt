import java.lang.Integer.max
import java.lang.Integer.min

// Thanks Be nQ!
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
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs(): List<Long> = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
// var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })  ,   
// ArrayList - ,   
// Array<Int>(n){0} - ,     
// ArrayList< ArrayList<Int> >() - 
// Array(n, { ArrayList<Pair<Int, Int>>() }) -  ,   
// val , var 
// ---------------------------------------------------
// var cnt = IntArray(MAX)
// var r = readInts()
//    for (x in r) cnt[x]++
//    3 (ok)
//val A = nextLongs()
//val a = Array<Long>(n,{0})
//for (i in 0..n-1) a[i] = A[i]
//a.sort()
//----------------------------------------------------
//   var
// mutableListOf<Int>() -         
//     - $x,$a
fun main(args: Array<String>) {
    var (n,m,q)=readInts()
    var a = Array(n){Array<Long>(m){0L} }
    for (i in 0 until n)
    {
        var f=readLongs()
        for (j in 0 until m)
        {
            a[i][j]=f[j]
        }
    }
    var row=Array<Long>(n){0L}
    var col=Array<Long>(m){0L}
    var sumrow=Array<Long>(n){0L}
    var sumcol=Array<Long>(m){0L}
    for (i in 0 until n)
    {
        var sum=0L
        for (j in 0 until m)
            sum+=a[i][j]
        sumrow[i]=sum
    }
    for (j in 0 until m)
    {
        var sum=0L
        for (i in 0 until n)
            sum+=a[i][j]
        sumcol[j]=sum
    }
    for (i in 0 until n)
    {
        var f=i-1
        var cnt=1L
        while (f>=0)
        {
            row[i]+=cnt*sumrow[f]
            f--
            cnt++
        }
        f=i+1
        cnt=1L
        while (f<n)
        {
            row[i]+=cnt*sumrow[f]
            f++
            cnt++
        }
    }
    for (j in 0 until m)
    {
        var f=j-1
        var cnt=1L
        while (f>=0)
        {
            col[j]+=cnt*sumcol[f]
            f--
            cnt++
        }
        f=j+1
        cnt=1L
        while (f<m)
        {
            col[j]+=cnt*sumcol[f]
            f++
            cnt++
        }
    }
    var min1=1000000000000000000L
    var min2=1000000000000000000L
    for (i in 0 until n)
        min1=kotlin.math.min(min1,row[i])
    for (i in 0 until m)
        min2=kotlin.math.min(min2,col[i])
    print(min1+min2)
    print(" ")
    while (q-->0)
    {
        var (x,y,z)=readInts()
        x--
        y--
        for (i in 0 until n)
            row[i]-=a[x][y]*kotlin.math.abs(i-x)
        for (i in 0 until m)
            col[i]-=a[x][y]*kotlin.math.abs(i-y)
        a[x][y]=1L*z
        for (i in 0 until n)
            row[i]+=a[x][y]*kotlin.math.abs(i-x)
        for (i in 0 until m)
            col[i]+=a[x][y]*kotlin.math.abs(i-y)
        min1=1000000000000000000L
        min2=1000000000000000000L
        for (i in 0 until n)
            min1=kotlin.math.min(min1,row[i])
        for (i in 0 until m)
            min2=kotlin.math.min(min2,col[i])
        print(min1+min2)
        print(" ")
    }

}