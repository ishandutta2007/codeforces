
fun readLn() = readLine()!! // string line
fun readInt() = readLn().toLong() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toLong() } // list of ints

fun main() {
    var t = readInt()
    while(t != 0L) {
        val (a,b,k) = readInts()
        val hk = k/2
        if(k%2 == 0L) {
            println(a*hk - b*hk)
        } else {
            println(a*(hk+1) - b*hk)
        }
        t--
    }
}