fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }


fun run() {
    val s = readLn()
    var ret = 0
    var seq = 0
    for(c in s) {
        if(c=='w') { 
            ++ret;
            seq = 0;
        } else {
            ret += seq
            seq = 1-seq
        }
    }
    println(ret)
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}