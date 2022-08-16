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

			var n = `in`.nextInt()
			var a = IntArray(n) { `in`.nextInt() + 1 }
			var u = IntArray(200010) { 0 }
			for (x in a)
			{
				u[x] += 1
			}
			for (x in u)
			{
				if (x >= 3)
				{
					out.println("NO")
					return
				}
			}
			
			var f = IntArray(n) { 0 }
			var q = ArrayDeque<Int>()
			for (i in n-1 downTo 0)
			{
				while (q.size > 0)
				{
					if (a[q.peekLast()] > a[i])
					{
						break
					}
					q.pollLast()
				}
				q.addLast(i)
				f[i] = q.size
			}

			var g = IntArray(n) { 0 }
			q = ArrayDeque<Int>()
			for (i in n-1 downTo 0)
			{
				while (q.size > 0)
				{
					if (a[q.peekLast()] < a[i])
					{
						break
					}
					q.pollLast()
				}
				q.addLast(i)
				g[i] = q.size
			}

			var m = 200001
			var w = IntArray(m + 10) { 0 }
			fun add(xx: Int, p: Int)
			{
				var x = xx
				while (x <= m)
				{
					w[x] += p
					x += x and (-x)
				}
			}
			fun get(xx: Int): Int
			{
				var x = xx
				var p = 0
				while (x > 0)
				{
					p += w[x]
					x -= x and (-x)
				}
				return p
			}
			
			out.println(f.joinToString())
			out.println(g.joinToString())

			for (i in n-1 downTo 0)
			{
				f[i] = if (f[i] - 1 == get(m) - get(a[i])) 1 else 0
				g[i] = if (g[i] - 1 == get(a[i] - 1)) 1 else 0
				add(a[i], 1)
			}

			out.println(f.joinToString())
			out.println(g.joinToString())

			var res = IntArray(n) { 0 }
			var low = 0
			var high = m + 1
			for (i in 0..n-1)
			{
				if ((low < a[i]) and (g[i] == 1))
				{
					low = a[i]
					res[i] = 0
				}
				else if ((high > a[i]) and (f[i] == 1))
				{
					high = a[i]
					res[i] = 1
				}
				else
				{
					out.println("NO")
					return
				}
			}
			out.println("YES")
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