import java.util.*
import java.io.*

val MOD = 998244353L

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

			var n = `in`.nextLong()
			var m = `in`.nextLong()
			var L = `in`.nextLong()
			var R = `in`.nextLong()
			var len = R-L+1
			
			if (n*m%2 == 1L) return out.println(power(len, n*m, MOD))

			var a = len/2
			var b = len-a
			if (L%2 == 0L)
			{
				var tmp = a
				a = b
				b = tmp
			}

			fun go(a: Long, b: Long, n: Long): Pair<Long, Long>
			{
				if (n == 0L) return Pair<Long, Long>(1, 0)
				var (c, d) = go(a, b, n/2)
				var (tc, td) = Pair<Long, Long>((c*c+d*d)%MOD, (2*c*d)%MOD)
				c = tc
				d = td
				if (n%2 == 1L)
				{
					var (sc, sd) = Pair<Long, Long>((a*c+b*d)%MOD, (a*d+b*c)%MOD)
					c = sc
					d = sd
				}
				return Pair<Long, Long>(c, d)
			}

			var (x, y) = go(a, b, n*m)
			out.println(x)
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