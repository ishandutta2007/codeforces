import java.util.*
import java.io.*
import java.math.*

val MOD = 998244353

fun main(args: Array<String>)
{
	Thread(null, Main(), "whatever", 1 shl 28).start()
}

class Main : Runnable
{

	override fun run()
	{
		val inputStream = System.`in`
		val outputStream = System.out
		val `in` = InputReader(inputStream)
		val out = PrintWriter(outputStream)
		val solver = TaskD()
		var test = 1
		//test = `in`.nextInt()
		for (t in 1..test)
		{
			solver.solve(t, `in`, out)
		}
		out.close()
	}

	internal class TaskD
	{
		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter)
		{
			val INF = 1000000000
			val dx = intArrayOf(-1, 1, 0, 0)
			val dy = intArrayOf(0, 0, -1, 1)

			var k = `in`.nextInt()
			var s = `in`.next()
			var t = `in`.next()
			var a = IntArray(k + 1) { if (it == 0) 0 else s[it - 1].toInt() - 'a'.toInt() }
			var b = IntArray(k + 1) { if (it == 0) 0 else t[it - 1].toInt() - 'a'.toInt() }
			var j = 0
			for (i in k downTo 0)
			{
				a[i] += b[i] + j
				j = a[i] / 26
				a[i] %= 26
			}
			j = 0
			for (i in 0..k)
			{
				a[i] = a[i] + j * 26
				j = a[i] % 2
				a[i] /= 2
			}
			var res = CharArray(k) { (a[it + 1] + 'a'.toInt()).toChar() }
			out.println(res.joinToString(""))
		}
	}

	internal class InputReader(stream: InputStream) {
		var reader: BufferedReader
		var tokenizer: StringTokenizer? = null

		init {
			reader = BufferedReader(InputStreamReader(stream), 32768)
			tokenizer = null
		}

		operator fun next(): String {
			while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
				try {
					tokenizer = StringTokenizer(reader.readLine())
				} catch (e: IOException) {
					throw RuntimeException(e)
				}

			}
			return tokenizer!!.nextToken()
		}

		fun nextInt(): Int {
			return Integer.parseInt(next())
		}

		fun nextLong(): Long {
		    return next().toLong()
		}

	}
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a%b)

fun power(a: Long, b: Long, p: Long): Long
{
	if (b == 0L) return 1L
	var t = power(a, b/2, p)
	t = t*t%p
	if (b%2 == 1L) t = t*a%p
	return t
}