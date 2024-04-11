import java.util.*
// author:  Mohamed Abo_Okail
// created: 22/O5/2O2O
fun main() {
    val sc = Scanner(System.`in`)
 
    val t = sc.nextInt()
    for (i in 0 until t) {
        var a = sc.nextInt()
        var b = sc.nextInt()
        var c = sc.nextInt()
        var d = sc.nextInt()
        if(a == c && a == b + d) println("Yes")
        else if(a == d && a == b + c) println("Yes")
        else if(b == c && b == a + d) println("Yes")
        else if(b == d && b == a + c) println("Yes")
        else println("No")
    }
}