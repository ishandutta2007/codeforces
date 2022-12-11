@file:Suppress("NOTHING_TO_INLINE", "EXPERIMENTAL_FEATURE_WARNING", "OVERRIDE_BY_INLINE")
 
import java.io.PrintWriter
import java.util.StringTokenizer
import kotlin.math.*
import kotlin.random.Random
import kotlin.collections.sort as _sort
import kotlin.collections.sortDescending as _sortDescending
import kotlin.io.println as iprintln
 
fun main() { _writer.solve(); _writer.flush() }
fun PrintWriter.solve() {

     //   val a=LongArray(4) {0}
       // for (i in 0 until 4)
      //  {
      //  a[i]=readLong()
      //  }
      //  a.sort()
      //  print(a[3]-a[0])
      //  print(" ")
      //  print(a[3]-a[1])
      //  print(" ")
      //  print(a[3]-a[2])
      val t=readInt()
      for (j in 0 until t)
      {
      val n=readLong()
      var a = ArrayList<Pair<Long, Long>>()
      for (i in 0 until n)
      {
      val b=readLong()
      val c=readLong()
      a.add(Pair(b,1L))
      a.add(Pair(c+1L,-1L))
      }
      var cnt=0L
      a.sortWith(compareBy({it.first},{it.second}))
      var k=0L
      var ans=0L
      var i=0
      while (i<2*n)
      {
      var j=i
      while (j<2*n&&a[i].first==a[j].first){
      cnt+=a[j].second
      j=j+1
      }
      if (cnt==1L)
      {
      k=1L
      ans=a[i].first
      }
      i=j
      }
      if (k==1L)
      {
      print(ans)
      print("\n")
      }
      else
      {
      print(-1)
      print("\n")
      }
      }
}
 
/** IO code start */
//@JvmField val INPUT = File("input.txt").inputStream()
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
 
@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
fun readList(): MutableList<Int> {return readLine()!!.split(' ').map{it.toInt()}.toMutableList()}
@JvmField val _writer = PrintWriter(OUTPUT, false)
 
/** shuffles and sort overrides to avoid quicksort attacks */
private inline fun <T> _shuffle(rnd: Random, get: (Int) -> T, set: (Int, T) -> Unit, size: Int) {
    // Fisher-Yates shuffle algorithm
    for (i in size - 1 downTo 1) {
        val j = rnd.nextInt(i + 1)
        val temp = get(i)
        set(i, get(j))
        set(j, temp)
    }
}
 
//@JvmField var _random: Random? = null
val random = Random(0x594E215C123 * System.nanoTime())
 
fun IntArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun IntArray.sort() { shuffle(); _sort() }
fun IntArray.sortDescending() { shuffle(); _sortDescending() }
 
fun LongArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun LongArray.sort() { shuffle(); _sort() }
fun LongArray.sortDescending() { shuffle(); _sortDescending() }
 
fun DoubleArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun DoubleArray.sort() { shuffle(); _sort() }
fun DoubleArray.sortDescending() { shuffle(); _sortDescending() }
 
fun CharArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
inline fun CharArray.sort() { _sort() }
inline fun CharArray.sortDescending() { _sortDescending() }
 
inline fun <T: Comparable<T>> Array<out T>.sort() = _sort()
inline fun <T: Comparable<T>> Array<out T>.sortDescending() = _sortDescending()
inline fun <T: Comparable<T>> MutableList<out T>.sort() = _sort()
inline fun <T: Comparable<T>> MutableList<out T>.sortDescending() = _sortDescending()
 
fun `please stop removing these imports IntelliJ`() {
    iprintln(max(1, 2))
}