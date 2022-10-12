import java.util.*
// author:  Mohamed Abo_Okail
// created: 2O/O2/2O2O
fun main() {
    val sc = Scanner(System.`in`)

    val ar = Array(4) { 0 }
    val ans = Array(3) { 0 }
    for (i in 0 until 4) {
        ar[i] = sc.nextInt()
    }
    ar.sort()
    ans[0] = ar[3] - ar[0]
    ans[1] = ar[3] - ar[1]
    ans[2] = ar[3] - ar[2]
    
    print(ans[0])
    print(' ')
    print(ans[1])
    print(' ')
    println(ans[2])
}