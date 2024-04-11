import java.util.*
// author:  Mohamed Abo_Okail
// created: 27/O5/2O2O
fun main() {
    val sc = Scanner(System.`in`)
 
    var t = sc.nextInt()
    while(t -- > 0) {
       var n = sc.nextInt()
       if(n <= 3) println(-1)
       else {
           for (i in n downTo 1) {
                if(i % 2 == 1) {
                    print(i)
                    print(' ')
                }
           }
           print("4 2 ")
           for (i in 6 until n + 1) {
               if(i % 2 == 0) {
                   print(i)
                   print(' ')
               }
           }
           println()
       }
    }
}