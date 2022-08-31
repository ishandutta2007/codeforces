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
			var a = IntArray(n+1)
			for (i in 1..n) a[i] = `in`.nextInt()
			var s = IntArray(n+1)
			for (i in 1..n) s[i] = s[i-1]+a[i]

			var MAXK = 18
			var f = Array<IntArray>(n+1, {IntArray(MAXK)})
			for (i in 0..n) f[i][0] = s[i]
			for (k in 1..MAXK-1)
				for (i in 0..n)
					f[i][k] = Math.min(f[i][k-1], f[Math.min(i+(1 shl (k-1)), n)][k-1])
			
			var lg = IntArray(n+1)
			for (i in 2..n) lg[i] = lg[i/2]+1
			fun rmq(x: Int, y: Int): Int
			{
				var k = lg[y-x+1]
				return Math.min(f[x][k], f[y-(1 shl k)+1][k])
			}

			var u = IntArray(61, {1})
			var res = -1000000000
			for (i in 1..n)
			{
				for (k in 0..a[i]+30-1)
					u[k] = i+1
				u[a[i]+30] = i+1
				for (k in 0..60)
				{
					var j = if (k == 60) 1 else u[k+1]
					if (j <= i)
					{
						var tmp = rmq(j-1, i-1)
						
						//out.println("$i $k ${j-1} ${i-1} $tmp")
						res = Math.max(res, s[i]-tmp-k+30)
					}
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