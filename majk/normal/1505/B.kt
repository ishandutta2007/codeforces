fun main(args: Array<String>) {
    var N = readLine()!!.toInt()
    while (N >= 10) {
        var ans = 0
        while (N > 0) {
            ans += N%10
            N /= 10
        }
        N = ans
    }
    println(N)
}