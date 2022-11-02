import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    var (n) = readLine()!!.split(' ').map(String::toInt)
    var ar = IntArray(n)
    var ar2 = readLine()!!.split(' ').map(String::toInt)
    
    for (i in (n - 1) downTo 0) {
        var k = ar2[i]
        for (j in (n - 2 - i) downTo k)
            ar[j + 1] = ar[j]
        ar[k] = i + 1
    }
    
    for (i in ar) {
        print(i)
        print(' ')
    }
}