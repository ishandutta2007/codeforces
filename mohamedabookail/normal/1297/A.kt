import java.util.*
// author:  Mohamed Abo_Okail
// created: 27/O2/2O2O
fun main() {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    for (i in 0 until n) {
        var x = sc.nextInt()
        if(x <= 999) println(x);
        else if(x <= 999999) {
            var ans = x / 1000
            if(x % 1000 >= 500) ans ++
            if(ans == 1000) {
                print(1)
                println('M')
            }
            else {
                print(ans)
                println('K')
            }
        }
        else {
            var ans = x / 1000000
            if(x % 1000000 >= 500000) ans ++
            print(ans)
            println('M')
        }
    }
}