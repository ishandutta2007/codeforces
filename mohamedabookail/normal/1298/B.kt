import java.util.*
// author:  Mohamed Abo_Okail
// created: 2O/O2/2O2O
fun main() {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    var cnt = 0
    val ar = Array(n) { 0 }
    val ans = Array(n) { 0 }
    for (i in 0 until n) {
        ar[i] = sc.nextInt()
    }
    ans[0] = ar[n - 1]
    for (i in n - 2 downTo 0) {
        var x = 1;
        for (j in cnt downTo 0) {
            if(ar[i] == ans[j]) {
                x = 0
            }
        }
        if(x == 1) {
            cnt ++
            ans[cnt] = ar[i]
        }
    }
    println(cnt + 1)
    for (i in cnt downTo 0) {
        print(ans[i])
        print(' ')
    }
}