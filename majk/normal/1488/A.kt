fun main(args: Array<String>) {
    val T=readLine()!!.toInt()
    repeat(T) {
        var (X,Y) = readLine()!!.split(" ").map { it.toInt() }
        var z = Y%X
        Y = Y/X
        while (Y > 0) {
            z += Y%10
            Y = Y/10
        }
        println(z)
    }
}