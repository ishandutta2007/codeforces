fun main() {
    val n = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map { it.toInt() }.sorted().toIntArray()
    val exists = BooleanArray(150_002)
    for (x in a) {
        if (x > 1 && !exists[x - 1]) exists[x - 1] = true
        else if (!exists[x]) exists[x] = true
        else exists[x + 1] = true
    }
    println(exists.count { it })
}