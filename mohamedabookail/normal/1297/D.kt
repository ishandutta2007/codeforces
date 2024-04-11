import java.util.*
// author:  Mohamed Abo_Okail
// created: 27/O2/2O2O
fun main() {
    val sc = Scanner(System.`in`)
    val t = sc.nextInt()
    for (j in 0 until t) {
        val n = sc.nextInt()
        var k = sc.nextInt()
        val ar1 = Array(n) { 0 }
        val ar2 = Array(n) { 0 }
        val ar3 = Array(n) { 0 }
        val ar4 = Array(n) { 0 }
        val ar5 = Array(n) { 0 }
        val mp = mutableMapOf < Int, Int > ()
        for (i in 0 until n) {
            ar1[i] = sc.nextInt()
            ar2[i] = ar1[i]
            ar5[i] = ar1[i]
        }
        ar2.sort()
        ar5.sort()
        for (i in 0 until n) {
            mp[ar5[i]] = i
        }
        for (i in n - 2 downTo 0) {
            var x = ar2[i + 1] - ar2[i]
            x --
            if(k >= x) {
                ar3[i] = x
                k = k - x
                ar2[i] = ar2[i] + x
            }
            else {
                ar3[i] = k
                k = 0
                break;
            }
        }
         if(k != 0) {
            var ans = k / n
            for (i in 0 until n) {
                ar3[i] = ar3[i] + ans;
            }
            ans = k % n
            for (i in n - 1 downTo 0) {
                if(ans == 0) break
                ar3[i] ++
                ans --
                if(ans == 0) break
            }
        }
        for (i in 0 until n) {
            val d = mp[ar1[i]]
            mp[ar1[i]] = d!!
            ar4[i] = ar3[d]
        }
        for (i in 0 until n) {
            print(ar4[i])
            print(' ')
        }
        println()
    }
}