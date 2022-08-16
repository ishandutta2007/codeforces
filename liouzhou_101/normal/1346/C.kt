import java.util.*
import java.io.*

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
		test = `in`.nextInt()
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
			var k = `in`.nextLong()
			var x = `in`.nextLong()
			var y = `in`.nextLong()
			var a = Array<Long>(n+1, {0L})
			for (i in 1..n) a[i] = `in`.nextLong()
			var sum = 0L
			for (c in a) sum += c
			if (a.max()!! <= k) return out.println(0)

			a.sort()
			var res = INF
			var cnt = 0L
			var del = 0L
			if (sum <= n*k) res = Math.min(res, y)
			for (i in n downTo 1)
			{
				cnt += 1
				del += a[i]
				if (a[i-1] <= k)
					res = Math.min(res, cnt*x)
				else
				{
					if (sum-del <= n*k) res = Math.min(res, cnt*x+y)
				}
			}
			out.println(res)
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