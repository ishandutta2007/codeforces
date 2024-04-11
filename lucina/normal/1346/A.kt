import java.math.BigInteger
 
fun readInt(): Int {
    return readLine()!!.toInt()
}
 
fun readLong(): Long {
    return readLine()!!.toLong()
}
 
fun readBigInt(): BigInteger {
    return readLine()!!.toBigInteger()
}
 
fun readInts(): List<Int> {
    return readLine()!!.split(" ").map(String::toInt)
}
 
fun readLongs(): List<Long> {
    return readLine()!!.split(" ").map(String::toLong)
}
 
fun readBigInts(): List<BigInteger> {
    return readLine()!!.split(" ").map(String::toBigInteger)
}

fun main () {
  
  val t = readInt()
  
  for (i in 0 until t) {
  	val (n, k) = readInts()
    /// x + kx + k^2x + k^3x = n
    val x = n / (1 + k + k * k + k * k * k)
    print(x)
    print(' ')
    print(x * k)
    print(' ')
    print(x * k * k)
    print(' ')
    println(x * k * k * k)
  }
}