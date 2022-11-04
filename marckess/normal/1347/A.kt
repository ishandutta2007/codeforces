private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readStrings().map { it.toInt() }
private fun readStrings() = readLn().split(" ")

fun main() {
	var t = readInt();

	for (kk in 1..t) {
		var (a, b) = readInts()
		println(a + b)
	}
}