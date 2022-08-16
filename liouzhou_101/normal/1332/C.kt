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

			var n = `in`.nextInt()
			var k = `in`.nextInt()
			var s = `in`.next()
			
			var f = IntArray(n, { x -> x })
			fun father(x: Int): Int
			{
				if (f[x] == x) return x
				f[x] = father(f[x])
				return f[x]
			}
			fun merge(x: Int, y: Int)
			{
				var fx = father(x)
				var fy = father(y)
				f[fx] = fy
			}
			for (i in 0..n-1) merge(i, n-i-1)
			for (i in 0..n-k-1) merge(i, i+k)

			var H = Array<HashMap<Char, Int>>(n, {HashMap<Char, Int>()})
			for (i in 0..n-1)
			{
				var x = father(i)
				if (H[x][s[i]] == null) H[x][s[i]] = 0
				H[x][s[i]] = H[x][s[i]]!!+1
			}

			var res = 0
			for (i in 0..n-1)
			{
				if (father(i) != i) continue
				var tmp = 0
				var sum = 0
				for ((x, y) in H[i])
				{
					tmp = Math.max(tmp, y)
					sum += y
				}
				res += sum-tmp
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