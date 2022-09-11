fun run() {
    val (n,step) = readLine()!!.split(" ").map{it.toInt()}
    var s = readLine()!!
    var rem = s.filter{c->c=='1'}.count()
    var at = 0
    var ans = 0
    while(rem>0) {
        ++ans
        if(s[at]=='1') --rem
        s=s.removeRange(at..at)
        if(rem==0) break
        at=(at+step-1)%s.length
    }
    println(ans)
}

fun main() {
    val ncase = readLine()!!.toInt()
    repeat(ncase) { run() }
}