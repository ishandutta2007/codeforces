fun main(args: Array<String>) {
    var (N, M) = readLine()!!.split(" ").map(String::toInt)
    var S = ""
    var Z = "0123456789ABCDEF"
    while (N > 0) {
        S = Z[N%M] + S
        N /= M
    }
    if (S.toSet().size == S.length) {
        println("YES")
    } else {
        println("NO")
    }
//    if (S.all { it == '0' || it == '1'} && S.reversed() == S) {
//        println("NO")
//    } else {
//        println("YES")
//    }
}