import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() }  // list of doubles

fun main() {
   var N = readInt()
   var str = mutableListOf<String>()
   for (i in 0..N-1) {
      str.add(readLn())
   }
   str.sortBy { it.length }
   var ok = true
   
   fun isSubstr(S0: String, S1: String): Boolean {
      for (i in 0..(S1.length - S0.length)) {
         if (S0 == S1.substring(i, i+S0.length)) return true
      }
      return false
   }
   
   for (i in 0..N-2) if (!isSubstr(str[i], str[i+1])) ok = false
   if (ok) {
      println("YES")
      for (s in str) println(s)
   } else {
      println("NO")
   }
}