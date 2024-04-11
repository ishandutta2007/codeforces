import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readInts() = readStrings().map { it.toInt() }
private fun readStrings() = readLn().split(" ")

fun main() {
	var t = readInt()

	for (kk in 1..t) {
		var n = readInt()
		var a = readInts()
		var i = 0
		var j = n - 1
		var x = 0
		var y = 0
		var act = 0
		var f = true
		var res = 0

		while (i <= j) {
			var acu = 0
			if (f) {
				while (i <= j && acu <= act)
					acu += a[i++]
				x += acu
			} else {
				while (i <= j && acu <= act)
					acu += a[j--]
				y += acu
			}
			act = acu
			f = !f
			res++
		}

		println("$res $x $y")
	}
}