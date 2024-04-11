fun main(args: Array<String>) {
    val s = readLine()!!
    val n = s.length
    for (i in 2 until n) {
        val a = s[i-2]-'A'
        val b = s[i-1]-'A'
        val c = s[i]-'A'
        if ((a+b)%26 != c) {
            println("NO")
            return
        }
    }
    println("YES")
}