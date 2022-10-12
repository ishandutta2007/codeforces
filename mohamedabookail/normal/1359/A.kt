import java.util.*
// author:  Mohamed Abo_Okail
// created: 29/O5/2O2O
fun main() {
    val sc = Scanner(System.`in`)
 
    var t = sc.nextInt()
    
    while(t-- > 0) {
        var n = sc.nextInt()
        var m = sc.nextInt()
        var k = sc.nextInt()
        var flag = n / k
        var mx = 0
        var cur = 0
        if(flag <= m) {
            mx = flag
            m -= flag
        }
        else {
            mx = m
            m = 0
        }
        k --
        cur = m / k
        if(m % k != 0) cur ++
        println(mx - cur)
    }
}