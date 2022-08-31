import java.util.*
import java.io.*

val MOD = 924844033

fun main(args: Array<String>)
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
			var m = `in`.nextInt()
			var s = Array<String>(n) { `in`.next() }
			
			if (n == 1) return out.println(s[0])

			var id = -1
			for (k in 1..n-1)
			{
				var cnt = 0
				for (i in 0..m-1)
					if (s[0][i] != s[k][i]) cnt += 1
				if (cnt > 2) return out.println(-1)
				if (cnt == 2) id = k
			}
			if (id == -1) return out.println(s[0])

			var v = ArrayList<Int>()
			for (i in 0..m-1)
				if (s[0][i] != s[id][i]) v.add(i)
			for (x in 'a'..'z')
				for (y in 'a'..'z')
				{
					var c = CharArray(m, { i -> if (i == v[0]) x else if (i == v[1]) y else s[0][i] })
					var flag = 0
					for (k in 0..n-1)
					{
						var cnt = 0
						for (i in 0..m-1)
							if (c[i] != s[k][i]) cnt += 1
						flag = Math.max(flag, cnt)
					}
					if (flag <= 1) return out.println(c.joinToString(""))
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