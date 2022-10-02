/**
 * Created by majk on 16.6.16.
 */

fun main(args: Array<String>) {
    var l = ' '
    var s = true
    var f = true
    for (ch in readLine()!!) {
        when (ch) {
            '.' -> { print('.'); s = true }
            ',' -> print(',')
            ' ' -> {}
            else -> {
                if (!f && l in "., ") print(' ')
                if (s) {
                print(ch.toUpperCase())
            } else {
                print(ch.toLowerCase())
            }; s = false; f = false; }

        }
        l = ch
    }

}