
fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    for(t in 1..n) {
        val s1 = readLine()!!
        val s2 = readLine()!!
        var i = 0
        var b = true
        for(c in s2) {
            if(i >= s1.length) {
                b = false
                break
            }
            if((c == '-' && s1[i] == '+') ||
                 (c == '+' && (s1[i] == '-' && (i + 1 >= s1.length || s1[i + 1] == '+')))) {
                b = false
                break
            }
            if(c == '+' && s1[i] == '-') {
                i++
            }
            i++
        }
        if(b && i == s1.length) {
            println("YES")
        }else {
            println("NO")
        }
    }
}