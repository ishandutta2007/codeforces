fun main() {
    val t = readLine()!!.toInt()
    for (tid in 1..t) {
         val (n, k) = readLine()!!.split(' ').map(String::toInt)
         val coef = k * k * k + k * k + k + 1
         val n1 = n / coef
         val n2 = n1 * k
         val n3 = n2 * k
         val n4 = n3 * k
         print(n1)
         print(' ')
         print(n2)
         print(' ')
         print(n3)
         print(' ')
         println(n4)
    }
}