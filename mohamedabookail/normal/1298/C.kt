import java.util.*
// author:  Mohamed Abo_Okail
// created: 2O/O2/2O2O
fun main() {
    var n = readLine()!!.toInt()
    var s = readLine()!!
    var cnt = 0
    var ans = 0
    s += '0'
    for (i in 0 until n + 1) {
        if(s[i] == 'x') {
            cnt ++
        }
        else {
            if(cnt > 2) {
                ans += cnt - 2
            }
            cnt = 0
        }
    }
    println(ans)
}