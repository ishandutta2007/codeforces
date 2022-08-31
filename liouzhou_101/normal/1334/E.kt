import java.util.*
import java.io.*

fun gcd(a: Long, b: Long): Long
{
	if (b == 0L) return a
	return gcd(b, a%b)
}

fun power(a: Long, b: Long, p: Long): Long
{
	if (b == 0L) return 1L
	var t = power(a, b/2, p)
	t = t*t%p
	if (b%2 == 1L) t = t*a%p
	return t
}

fun main() {
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

	internal class TaskD {
		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
			val INF = 1000000000
			val MOD = 998244353L
			val dx = intArrayOf(-1, 1, 0, 0)
			val dy = intArrayOf(0, 0, -1, 1)

			var D = `in`.nextLong()
			var primes = ArrayList<Long>()
			for (i in 2..10000000)
			{
				if (D%i == 0L)
				{
					primes.add(i.toLong())
					while (D%i == 0L) D /= i
					if (D == 1L) break
				}
			}
			if (D > 1) primes.add(D)
			var len = primes.size

			var fact = LongArray(60+1)
			var rfact = LongArray(60+1)
			fact[0] = 1L
			for (i in 1..60) fact[i] = fact[i-1]*i%MOD
			for (i in 0..60) rfact[i] = power(fact[i], MOD-2, MOD)

			fun getTable(x: Long): IntArray
			{
				var n = x
				var res = IntArray(len, {0})
				for (i in 0..len-1)
				{
					while (n%primes[i] == 0L)
					{
						n /= primes[i]
						res[i] += 1
					}
				}
				return res
			}

			fun calc(a: IntArray): Long
			{
				var res = 1L
				for (x in a) res *= x+1
				return res
			}

			fun solve(a: IntArray, b: IntArray): Long
			{
				var res = 1L
				var cnt = 0
				for (i in 0..len-1)
				{
					var tmp = a[i]-b[i]
					cnt += tmp
					res = res*rfact[tmp]%MOD
				}
				res = res*fact[cnt]%MOD
				return res
			}

			var tests = `in`.nextInt()
			for (test in 1..tests)
			{
				var x = `in`.nextLong()
				var y = `in`.nextLong()
				if (x > y)
				{
					var tmp = x
					x = y
					y = tmp
				}
				if (x == y)
				{
					out.println(1)
					continue
				}
				var d = gcd(x, y)
				var m = x/d*y
				var xt = getTable(x)
				var yt = getTable(y)
				var dt = getTable(d)
				var mt = getTable(m)
				var xc = calc(xt)
				var yc = calc(yt)
				var dc = calc(dt)
				var mc = calc(mt)
				var res = 0L
				if (xc-dc+yc-dc <= mc-xc+mc-yc)
				{
					var tmp1 = solve(xt, dt)
					var tmp2 = solve(yt, dt)
					res = (res+tmp1*tmp2)%MOD
				}
				if (xc-dc+yc-dc >= mc-xc+mc-yc && m != y)
				{
					var tmp1 = solve(mt, xt)
					var tmp2 = solve(mt, yt)
					res = (res+tmp1*tmp2)%MOD
				}
				out.println(res)
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