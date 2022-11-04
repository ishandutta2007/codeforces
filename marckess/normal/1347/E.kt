import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readStrings().map { it.toInt() }
private fun readStrings() = readLn().split(" ")

fun main() {
	var t = readInt()

	for (kk in 1..t) {
		var n = readInt()
		var a: Array<ArrayList<Int>> = Array(4) { ArrayList<Int>() }

		if (n < 4) {
			println(-1)
			continue
		}

		for (i in 1..n)
			a[i % 4].add(i)

		println(a[3].joinToString(" ") + " " + a[1].reversed().joinToString(" ") + " " + a[0].joinToString(" ") + " " + a[2].reversed().joinToString(" "))
	}
}