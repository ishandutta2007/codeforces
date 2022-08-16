import java.util.*
import java.io.*

val MOD = 998244353

fun main()
{
	Thread(null, Main(), "whatever", 1 shl 28).start()
}

class Main : Runnable {

	override fun run()
	{
		val inputStream = System.`in`
		val outputStream = System.out
		val `in` = InputReader(inputStream)
		val out = PrintWriter(outputStream)
		val solver = TaskD()
		var test = 1
		test = `in`.nextInt()
		for (t in 1..test)
		{
			solver.solve(t, `in`, out)
		}
		out.close()
	}

	internal class TaskD
	{
		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
			val INF = 4000000000000000000L
			val dx = intArrayOf(-1, 1, 0, 0)
			val dy = intArrayOf(0, 0, -1, 1)

			var a = `in`.nextInt()
			var b = `in`.nextInt()
			var c = `in`.nextInt()
			var d = `in`.nextInt()
			var x = `in`.nextInt()
			var y = `in`.nextInt()
			var x1 = `in`.nextInt()
			var y1 = `in`.nextInt()
			var x2 = `in`.nextInt()
			var y2 = `in`.nextInt()

			fun check(a: Int, b: Int, x1: Int, x: Int, x2: Int): Boolean
			{
				if (x1 == x2)
				{
					return a == 0 && b == 0
				}
				if (b >= a)
				{
					return x2-x >= b-a
				}
				else
				{
					return x-x1 >= a-b
				}
			}

			out.println(if (check(a, b, x1, x, x2) && check(c, d, y1, y, y2)) "YES" else "NO")

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