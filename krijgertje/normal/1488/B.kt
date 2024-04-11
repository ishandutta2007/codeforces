fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }

fun run() {
    val (n,lim) = readInts()
    val s = readLn()
    val bal = IntArray(n+1)
    bal[0] = 0
    for(i in 0..n-1) bal[i+1]=bal[i]+(if(s[i]=='(') +1 else -1)
    val nparts = bal.filter{it==0}.size-1
    println(nparts+minOf(lim,(n-2*nparts)/2))
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}