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
 
			var n = `in`.nextInt()
			var m = `in`.nextInt()
			var q = `in`.nextInt()
			var a = Array<LongArray>(n, {LongArray(m, {`in`.nextLong()})})
			var sx = LongArray(n)
			var sy = LongArray(m)
			var sum = 0L
			for (i in 0..n-1)
				for (j in 0..m-1)
				{
					sx[i] += a[i][j]
					sy[j] += a[i][j]
					sum += a[i][j]
				}


			var res = LongArray(q+1)
			for (qq in 0..q)
			{
				if (qq > 0)
				{
					var x = `in`.nextInt()-1
					var y = `in`.nextInt()-1
					var z = `in`.nextLong()
					sx[x] -= a[x][y]
					sy[y] -= a[x][y]
					sum -= a[x][y]
					a[x][y] = z
					sx[x] += a[x][y]
					sy[y] += a[x][y]
					sum += a[x][y]
				}
				var cur = 0L
				var tmp = 0L
				for (i in 0..n-1)
				{
					tmp += sx[i]
					if (tmp*2 >= sum)
					{
						for (j in 0..n-1)
						{
							cur += sx[j]*Math.abs(i-j)
						}
						break
					}
				}
				tmp = 0L
				for (i in 0..m-1)
				{
					tmp += sy[i]
					if (tmp*2 >= sum)
					{
						for (j in 0..m-1)
						{
							cur += sy[j]*Math.abs(i-j)
						}
						break
					}
				}
				res[qq] = cur
			}
			out.println(res.joinToString(" "))
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