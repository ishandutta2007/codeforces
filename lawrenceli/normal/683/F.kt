import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    var s = readLine()!!
    var t = ""
    var cap = true
    var first = false
    
    for (i in s.indices) {
        if (s[i] == ' ') {
            if (first) {
                if (t[t.length - 1] != ' ')
                t = t.plus(' ')
            }
        } else if ((s[i] == ',') or (s[i] == '.')) {
            if ((t.length > 0) and (t[t.length - 1] == ' ')) {
                t = t.substring(0, t.length - 1)
            }
            t = t.plus(s[i])
            t = t.plus(' ')
            
            if (s[i] == '.') cap = true
        } else {
            if (cap) t = t.plus(s[i].toUpperCase())
            else t = t.plus(s[i].toLowerCase())
            cap = false
            first = true
        }
    }
    
    while (t[t.length - 1] == ' ')
        t = t.substring(0, t.length - 1)
    println(t)
}