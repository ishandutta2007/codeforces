import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    var freq = IntArray(2005, {i -> 0})
    var ar1 = readLine()!!.split(' ').map(String::toInt)
    var ar2 = readLine()!!.split(' ').map(String::toInt)
    
    for (i in ar1.indices) {
        if (i > 0) {
            freq[ar1[i] + 1000]++
        }
    }
    
    for (i in ar2.indices) {
        if (i > 0) {
            freq[ar2[i] + 1000]++
        }
    }
    
    var cnt = 0
    for (i in freq.indices) {
        if (freq[i] == 1) cnt++
    }
    
    var ar = IntArray(cnt)
    var cur = 0
    
    for (i in freq.indices) {
        if (freq[i] == 1) {
            ar[cur] = i - 1000
            cur++
        }
    }
    
    print(ar.size)
    print(' ')
    for (i in ar) {
        print(i)
        print(' ')
    }
}