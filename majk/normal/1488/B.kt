import java.lang.Integer.min

fun main(args: Array<String>) {
    val T=readLine()!!.toInt()
    repeat(T) {
        val (N,K) = readLine()!!.split(" ").map { it.toInt() }
        var c = 0
        var z = 0
        val S = readLine()!!
        for (s in S) {
            if (s == '(') {
                z += 1
            } else {
                z -= 1
                if (z == 0) c += 1
            }
        }
        println(min(N/2, c + K))
    }
}