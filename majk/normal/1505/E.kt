fun main(args: Array<String>) {
    val (R,C) =  readLine()!!.split(" ").map(String::toInt)
    val A = (0 until R).map { readLine()!! }
    var r = 0
    var c = 0
    var ans = if (A[0][0] == '*') 1 else 0
    while (r != R-1 || c != C-1) {
        if (r == R-1) {
            c++
        } else if (c == C-1) {
            r++
        } else if (A[r][c+1] == '*') {
            c++
        } else if (A[r+1][c] == '*') {
            r++
        } else {
            c++
        }
        if (A[r][c] == '*') ans++
    }

    println(ans)
}