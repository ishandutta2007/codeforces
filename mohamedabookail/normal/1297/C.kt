import java.util.*
// author:  Mohamed Abo_Okail
// created: 27/O2/2O2O
fun main() {
    val sc = Scanner(System.`in`)
    val t = sc.nextInt()
    for (j in 0 until t) {
        var sum = 0
        var inx = -1
        var iny = -1
        var mn = -100000
        var mx = 100000
        val n = sc.nextInt()
        val ar = Array(n) { 0 }
        val ans = Array(n) { 0 }
        for (i in 0 until n) {
             ar[i] = sc.nextInt()
             if(ar[i] > 0) {
                sum = sum + ar[i]
                ans[i] = 1
                if(ar[i] < mx) {
                    iny = i;
                    mx = ar[i]
                }
             }
             else if(ar[i] < 0) {
                if(ar[i] > mn) {
                    inx = i
                    mn = ar[i]
                }
            }
        }
        if(inx != -1) {
            if(mx < mn * -1) {
                sum = sum - ar[iny]
                ans[iny] = 0
            }
            else {
                sum = sum + ar[inx]
                ans[inx] = 1
            }
        }
        else {
            sum = sum - ar[iny]
            ans[iny] = 0
        }
        println(sum)
        for (i in 0 until n) {
            print(ans[i])
        }
        println()
    }
}