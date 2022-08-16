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
		test = `in`.nextInt()
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
			var edge = Array<IntArray>(m, {IntArray(3, {`in`.nextInt()})})
			edge.sortWith(compareBy({it[2]}))

			var v = Array<ArrayList<Pair<Int, Int>>>(n, {ArrayList<Pair<Int, Int>>()})
			var h = Array<TreeMap<Int, Int>>(n, {TreeMap<Int, Int>()})
			var a = IntArray(n, {-1})
			var d = IntArray(n, {0})
			var go = TreeMap<Int, TreeSet<Int>>()
			for (e in edge)
			{
				var x = e[0]-1
				var y = e[1]-1
				var z = e[2]
				v[x].add(Pair<Int, Int>(y, z))
				v[y].add(Pair<Int, Int>(x, z))
				if (h[x][z] == null) h[x][z] = 0
				h[x][z] = h[x][z]!!+1
				if (h[y][z] == null) h[y][z] = 0
				h[y][z] = h[y][z]!!+1
				d[x] ++
				d[y] ++
				if (go[z] == null) go[z] = TreeSet<Int>()
				go[z]!!.add(x)
				go[z]!!.add(y)
			}
			for (w in go.keys)
			{
				var q = LinkedList<Int>()
				for (x in go[w]!!)
				{
					if (d[x] == h[x][w]!! && h[x].firstKey()!! == w)
					{
						q.add(x)
					}
				}
				while (!q.isEmpty())
				{
					var x = q.poll()!!
					a[x] = w
					for ((y, z) in v[x])
					{
						d[y] --
						if (h[y].containsKey(w))
						{
							h[y][w] = h[y][w]!!-1
							if (h[y][w]!! == 0) h[y].remove(w)
						}
					}
				}
			}
			if ((0..n-1).any({a[it] == -1})) return out.println("NO")

			out.println("YES")
			out.println(a.joinToString(" "))
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