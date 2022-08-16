import java.util.*
import java.io.*

val MOD = 924844033

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
			val INF = 4000000000000000000L
			val dx = intArrayOf(-1, 1, 0, 0)
			val dy = intArrayOf(0, 0, -1, 1)

			var n = `in`.nextInt()
			var halfn = (n+1)/2
			var a = LongArray(n+1)
			for (i in 1..halfn) a[i] = `in`.nextLong()
			var x = `in`.nextLong()
			for (i in halfn+1..n) a[i] = x
			for (i in 1..n) a[i] += a[i-1]
			if (a[n] > 0) return out.println(n)
			if (x >= 0) return out.println(-1)
			var b = IntArray(n+1)
			var k = n
			for (i in 1..halfn)
			{
				var tmp = a[halfn]-a[i-1]
				if (tmp <= 0) return out.println(-1)
				b[i] = Math.min((tmp-1)/(-x), n/2L).toInt()
				k = Math.min(k, halfn-i+1+b[i])
				if (i+k-1 == n) return out.println(k)
			}
			out.println(-1)
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