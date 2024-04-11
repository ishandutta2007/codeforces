fun main() {
    readLine()
    val line = readLine()!!
    for (i in 0 until line.length) {
        if (i * (i + 1) / 2 !in line.indices) break
        print(line[i * (i + 1) / 2])
    }
}