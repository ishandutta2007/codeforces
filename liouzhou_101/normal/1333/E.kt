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
		//test = `in`.nextInt()
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

			var n = `in`.nextInt()
			if (n <= 2) return out.println(-1)
			var a = Array<Array<Int>>(n, {Array<Int>(n, {0})})
			a[0][0] = 9+n*n-9
			a[0][1] = 5+n*n-9
			a[0][2] = 6+n*n-9
			a[1][0] = 7+n*n-9
			a[1][1] = 2+n*n-9
			a[1][2] = 8+n*n-9
			a[2][0] = 1+n*n-9
			a[2][1] = 3+n*n-9
			a[2][2] = 4+n*n-9
			var cur = n*n-9
			for (i in 3..n-1)
			{
				if (i%2 == 1)
				{
					for (j in 0..i)
					{
						a[i][j] = cur
						cur --
					}
					for (j in i-1 downTo 0)
					{
						a[j][i] = cur
						cur --
					}
				}
				else
				{
					for (j in 0..i)
					{
						a[j][i] = cur
						cur --
					}
					for (j in i-1 downTo 0)
					{
						a[i][j] = cur
						cur --
					}
				}
			}

			for (i in 0..n-1)
				out.println(a[i].joinToString(" "))
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