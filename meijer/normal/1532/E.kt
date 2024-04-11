
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints

fun main() {
    val n = readInt()
    val a = readInts()
	val b = a.sorted()
    
    var total = a.sum()
    var answer: MutableList<Int> = ArrayList()
    
    for(i in 0 until n) {
        if(total - a[i] == (if (a[i] == b[n-1]) { b[n-2] } else { b[n-1]})*2L ) {
            answer.add(i+1)
        }
    }
    println(answer.size)
    println(answer.joinToString(separator = " "))
}