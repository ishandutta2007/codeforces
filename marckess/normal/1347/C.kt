import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readStrings().map { it.toInt() }
private fun readStrings() = readLn().split(" ")

fun main() {
	var t = readInt()

	for (kk in 1..t) {
		var n = readLn().reversed()
		var aux = ""
		var res = ArrayList<String>()

		for (c in n) {
			if (c != '0') res.add(c + aux)
			aux += "0"
		}

		println(res.size)
		for (r in res)
			print(r + ' ')
		print('\n')
	}
}