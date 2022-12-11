import java.util.*
 
fun main() {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    var t=-1L
    var f=-1
    val a = Array(n) { 0L }
    for (i in 0 until n) {
        a[i] = sc.nextLong()
        if (a[i]>=t)
        {
        t=a[i]
        f=i
        }
    }
    val res=(t-1)*n + f+1
    println(res)
}