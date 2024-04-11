fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    val R = readLine()!!.split(" ").map { it.toInt() }
    val RC = R.max()
    val RA = R.min()
    var A = -1
    var B = -1
    var C = -1
    for (i in 0 until N) {
        if (R[i] == RA) A = i+1
        else if (R[i] == RC) C = i+1
        else B = i+1
    }
    if (A == -1 || B == -1 || C == -1) {
        A = -1
        B = -1
        C = -1
    }

    println("$A $B $C")
}