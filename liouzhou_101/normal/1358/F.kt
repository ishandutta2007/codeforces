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
			var a = LongArray(n, {`in`.nextLong()})
			var b = LongArray(n, {`in`.nextLong()})
			if (n == 1)
			{
				if (a[0] != b[0]) return out.println("IMPOSSIBLE")
				out.println("SMALL")
				out.println(0)
				out.println()
				return
			}
			if (n == 2)
			{
				var pre = ArrayList<Pair<Long, Char>>()
				var suf = ArrayList<Pair<Long, Char>>()
				if (a[0] > a[1])
				{
					pre.add(Pair<Long, Char>(1, 'R'))
					var tmp = a[0]
					a[0] = a[1]
					a[1] = tmp
				}
				if (b[0] > b[1])
				{
					suf.add(Pair<Long, Char>(1, 'R'))
					var tmp = b[0]
					b[0] = b[1]
					b[1] = tmp
				}
				while (b[0] > a[0])
				{
					suf.add(Pair<Long, Char>(b[1]/b[0], 'P'))
					suf.add(Pair<Long, Char>(1, 'R'))
					b[1] %= b[0]
					var tmp = b[0]
					b[0] = b[1]
					b[1] = tmp
				}
				if (b[0] < a[0]) return out.println("IMPOSSIBLE")
				if (b[1] < a[1]) return out.println("IMPOSSIBLE")
				if ((b[1]-a[1])%a[0] != 0L) return out.println("IMPOSSIBLE")
				suf.add(Pair<Long, Char>((b[1]-a[1])/a[0], 'P'))
				var cnt = 0L
				for ((x, y) in suf)
				{
					if (y == 'P') cnt += x
				}
				if (cnt > 200000)
				{
					out.println("BIG")
					out.println(cnt)
					return
				}
				var head = if (pre.isEmpty()) "" else "R"
				var tmp = ArrayList<Char>()
				for ((x, y) in suf)
				{
					for (i in 1..x) tmp.add(y)
				}
				var res = head+tmp.reversed().joinToString("")
				out.println("SMALL")
				out.println(res.length)
				out.println(res)
				return
			}
			var res = ArrayList<Char>()
			while (true)
			{
				if ((0..n-1).all({a[it] == b[n-it-1]}))
				{
					res.add('R')
					b.reverse()
				}
				if ((0..n-1).all({a[it] == b[it]})) break
				if (b[0] > b[n-1])
				{
					res.add('R')
					b.reverse()
				}
				if (b.min()!! < a.min()!!) return out.println("IMPOSSIBLE")
				if ((1..n-1).any({b[it] <= b[it-1]})) return out.println("IMPOSSIBLE")
				res.add('P')
				for (i in n-1 downTo 1)
					b[i] -= b[i-1]
			}
			res.reverse()
			if (res.size > 200000)
			{
				out.println("BIG")
				var cnt = 0
				for (c in res) if (c == 'P') cnt ++
				out.println(cnt)
			}
			else
			{
				out.println("SMALL")
				out.println(res.size)
				out.println(res.joinToString(""))
			}
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