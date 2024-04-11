import java.util.*
// author:  Mohamed Abo_Okail
// created: 22/O5/2O2O
fun main() {
    val sc = Scanner(System.`in`)
 
    val t = sc.nextInt()
    for (i in 0 until t) {
        var n = sc.nextInt()
        var cnt = 0
        var inx = 0
        val ar = Array(5) { 0 }
        for (j in 0 until 5) {
            if(n % 10 != 0) {
                ar[inx] = n % 10
                for (k in 0 until j) {
                    ar[inx] *= 10
                }
                inx ++
                cnt ++
            }
            n = n / 10
            if(n == 0) break
        }
        println(cnt)
        for (j in 0 until cnt) {
            print(ar[j])
            print(' ')
        }
        println()
    }
}