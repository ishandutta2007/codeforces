fun main() {
    readLine()
    val fileName = readLine()!!
    println((2 until fileName.length).count { fileName[it] == fileName[it - 1] && fileName[it] == fileName[it - 2] && fileName[it] == 'x' })
}