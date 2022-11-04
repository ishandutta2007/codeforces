import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readStrings().map { it.toInt() }
private fun readStrings() = readLn().split(" ")

fun main() {
	var t = readInt();

	for (kk in 1..t) {
		var (a1, b1) = readInts()
		var (a2, b2) = readInts()

		println(if (max(a1, b1) == max(a2, b2) && min(a1, b1) + min(a2, b2) == max(a1, b1)) "Yes" else "No")
	}
}