fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

class A(val id: Int, val v: Int) {}

fun run() {
    val (n) = readInts()
    val a = readInts().mapIndexed{idx,value -> A(idx+1,value)}.toMutableList()
    a.sortBy{it.v}
    var nreplace = 0
    var replacesum = 0
    while(nreplace<n) {
        val need = a[nreplace].v-(if(nreplace!=0) 1 else 0)
        if(replacesum+need > n-(nreplace+1)) break
        replacesum+=need
        ++nreplace
    }
    //println("res $nreplace $replacesum")
    var ret = mutableListOf<Int>()
    var at = nreplace
    for(i in 0 until nreplace) {
        val need = a[i].v-(if(i!=0) 1 else 0)
        repeat(need) {
            ret.add(a[at++].id)
        }
        ret.add(a[i].id)
    }
    while(at<n) ret.add(a[at++].id)
    println(ret.joinToString(" "))
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}