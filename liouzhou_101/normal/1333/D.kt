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

			var n = `in`.nextInt()
			var k = `in`.nextInt()
			var s = `in`.next()
			var a = IntArray(n, { x -> if (s[x] == 'L') 0 else 1 })
			
			var cnt = 0
			for (i in 0..n-1)
				for (j in i+1..n-1)
					if (a[i] > a[j]) cnt += 1
			if (cnt < k) return out.println(-1)
			
			var res = ArrayList<IntArray>()

			while (k > 0 && cnt > k)
			{
				var need = cnt-k+1
				var tmp = ArrayList<Int>()
				for (x in 0..n-2)
				{
					if (a[x] == 1 && a[x+1] == 0) tmp.add(x)
				}
				var len = Math.min(need, tmp.size)
				var choose = IntArray(len, { x -> tmp[x] })
				res.add(choose)
				cnt -= len
				k -= 1
				for (x in choose)
				{
					a[x] = 0
					a[x+1] = 1
				}
				if (len == need) break
			}

			if (cnt != k) return out.println(-1)

			for (go in res)
			{
				out.print(go.size)
				for (i in 0..go.size-1) out.print(" ${go[i]+1}")
				out.println()
			}
			for (i in n-1 downTo 0)
			{
				if (a[i] == 0) continue
				for (j in i..n-2)
				{
					if (a[j+1] == 1) break
					out.println("1 ${j+1}")
					a[j] = 0
					a[j+1] = 1
				}
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