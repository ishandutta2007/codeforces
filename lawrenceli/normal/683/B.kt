import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val(n) = readLine()!!.split(' ').map(String::toInt)
    val ar = Array(n, {i -> Pair(0, "")})
    for (i in ar.indices) {
        val(x, y) = readLine()!!.split(' ')
        val z : Int = y.toInt()
        ar.set(i, Pair(z, x))
    }
    
    for (i in 0..(n-1)) {
        for (j in 1..(n-1)) {
            if (ar.get(j).first < ar.get(j - 1).first) {
                val k : Pair<Int, String> = ar.get(j)
                val k2 : Pair<Int, String> = ar.get(j - 1)
                ar.set(j, k2)
                ar.set(j - 1, k)
            }
        }
    }
    
    for (i in ar.indices) {
        println(ar.get(i).second)
    }
}