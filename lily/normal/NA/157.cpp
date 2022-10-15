private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var n = readInt()
    var a = readInts()
    var mx = 0L;
    var nom = 0;
    for(i in 0..n-1){
        if(a[i]>=mx){
            mx=a[i].toLong();
            nom=i;
        }
    }
    println((mx-1)*n+nom+1);
}