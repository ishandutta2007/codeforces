private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
 
fun main() {
    var t=readInt()
    for (i in 0..t-1) {
        var a=readInt()
        if (a<=999) println("${a}");
        else if (a<=999499) println("${(a+500)/1000}K");
        else println("${(a+500000)/1000000}M");
    }
}