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
			val INF = 4000000000000000000L
			val MOD = 998244353L
			val dx = intArrayOf(-1, 1, 0, 0)
			val dy = intArrayOf(0, 0, -1, 1)

			var n = `in`.nextInt()+1
			var a = IntArray(n+1)
			var v = Array<ArrayList<Int>>(n+1, {ArrayList()})
			for (i in 1..n-1) a[i] = `in`.nextInt()
			a[n] = n
			for (i in 1..n) v[a[i]].add(i)
			var c = LongArray(n+1)
			for (i in 1..n-1) c[i] = `in`.nextLong()
			var m = `in`.nextInt()
			var b = IntArray(n+1)
			for (i in 1..m) b[`in`.nextInt()] = 1
			b[n] = 1

			fun check(): Boolean
			{
				var pos = 1
				for (i in 1..n)
				{
					if (b[i] == 0) continue
					while (pos <= n && a[pos] != i) pos += 1
					if (pos > n) return false
				}
				return true
			}

			if (!check())
			{
				out.println("NO")
				return
			}
			out.println("YES")

			var w = LongArray(n+1)
			fun add(i: Int, p: Long)
			{
				var x = i
				while (x <= n)
				{
					w[x] += p
					x += x.and(-x)
				}
			}
			fun get(i: Int): Long
			{
				var res = 0L
				var x = i
				while (x != 0)
				{
					res += w[x]
					x -= x.and(-x)
				}
				return res
			}
			
			var last = 0
			var f = LongArray(n+1, {-INF})
			for (i in 1..n)
			{
				if (b[i] == 0) continue
				if (last == 0)
				{
					for (pos in v[i]) f[pos] = c[pos]
				}
				else
				{
					var tmp = -INF
					var id = 0
					for (pos in v[last])
					{
						while (id < v[i].size && v[i][id] < pos)
						{
							f[v[i][id]] = tmp+get(v[i][id])+c[v[i][id]]
							id += 1
						}
						tmp = Math.max(tmp, f[pos]-get(pos))
					}
					while (id < v[i].size)
					{
						f[v[i][id]] = tmp+get(v[i][id])+c[v[i][id]]
						id += 1
					}
				}
				for (j in last+1..i)
					for (pos in v[j])
					{
						add(pos, Math.max(0L, c[pos]))
					}
				last = i
			}

			var sum = 0L
			for (i in 1..n) sum += c[i]
			var res = f[n]
			res = sum-res
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