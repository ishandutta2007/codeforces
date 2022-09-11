fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }

fun run() {
    val (x,y) = readInts()
    tailrec fun digsum(n : Int) : Int = if(n==0) 0 else digsum(n/10)+(n%10)
    println(digsum(y/x)+(y%x))
}

fun main() {
    val (ncase) = readInts()
    for(i in 1..ncase) run()
}