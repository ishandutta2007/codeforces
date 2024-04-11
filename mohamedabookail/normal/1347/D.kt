import java.util.*
// author:  Mohamed Abo_Okail
// created: 27/O5/2O2O
fun main() {
    val sc = Scanner(System.`in`)
 
    var t = sc.nextInt()
    while(t -- > 0) {
       var n = sc.nextInt()
       val ar = Array(n) { 0 }
       var sum1 = 0
       var sum2 = 0
       var cnt = 0
       var a = 0
       var b = 0
       var inx = n - 1
       var flag = 0
       for (i in 0 until n) {
           ar[i] = sc.nextInt()
       }
       for (i in 0 until n) {
           if(flag > 0) {
               flag --
               continue
           }
           if(i > inx) break
           if(a <= b) {
               for (j in i until n) {
                    a = a + ar[j]
                    if(a > b || j >= inx) {
                        break
                    }
                    flag ++
               }
               sum1 = sum1 + a
               b = 0
               cnt ++
           }
           else {
               for (j in inx downTo 0) {
                   b = b + ar[j]
                   if(b > a || j <= i) {
                       inx = j - 1
                       break
                   }
               }
               sum2 = sum2 + b
               a = 0
               cnt ++
               if(i <= inx) {
                    a = ar[i]
                    if(a > b || i == inx) {
                        sum1 = sum1 + a
                        b = 0
                        cnt ++
                    }     
               }
           }
       }
       print(cnt)
       print(' ')
       print(sum1)
       print(' ')
       println(sum2)
    }
}