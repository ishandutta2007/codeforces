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
			var x = `in`.nextLong()
			var a = LongArray(n*2+1)
			var b = LongArray(n*2+1)
			for (i in 1..n)
			{
				a[i] = `in`.nextLong()
				a[i+n] = a[i]
			}
			for (i in 1..n*2)
			{
				b[i] = b[i-1]+a[i]*(a[i]+1)/2
				a[i] += a[i-1]
			}
			var j = 0
			var res = 0L
			for (i in n+1..n*2)
			{
				while (a[i]-a[j] >= x) j++
				var sum = a[i]-a[j]
				var tmp = (2*(a[j]-a[j-1])-(x-sum)+1)*(x-sum)/2+b[i]-b[j]
				res = Math.max(res, tmp)
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