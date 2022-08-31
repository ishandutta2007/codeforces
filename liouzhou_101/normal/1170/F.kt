import java.util.*
import java.io.*
import kotlin.math.*
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
fun main() {
	val inputStream = System.`in`
	val outputStream = System.out
	val `in` = Main.InputReader(inputStream)
	val out = PrintWriter(outputStream)
	val solver = Main.TaskD()
	solver.solve(1, `in`, out)
	out.close()
}
 
object Main {
	@JvmStatic
	fun main(args: Array<String>) {
		val inputStream = System.`in`
		val outputStream = System.out
		val `in` = InputReader(inputStream)
		val out = PrintWriter(outputStream)
		val solver = TaskD()
		solver.solve(1, `in`, out)
		out.close()
	}
 
	internal class TaskD {
		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
			val INF = 1000000000000000000L
			var n = `in`.nextInt()
			var m = `in`.nextInt()
			var k = `in`.nextLong()
			var a = Array<Long>(n+1, {x -> 0})
			var s = Array<Long>(n+1, {x -> 0})
			for (i in 1..n)
			{
				a[i] = `in`.nextLong()
			}
			a.sort()
			for (i in 1..n)
			{
				s[i] = s[i-1]+a[i]
			}
			var x = 1
			var ans = INF
			for (l in 1..n)
			{
				while (x <= n && (x-l+1)*a[x]-(s[x]-s[l-1]) <= k) ++ x
				var r = l+m-1
				if (r <= n)
				{
					var y = minOf(x-1, (l+r+1)/2)
					var tmp = (s[r]-s[y])-(r-y)*a[y]+(y-l+1)*a[y]-(s[y]-s[l-1])
					ans = minOf(ans, tmp)
					var L = y-l+1
					var R = r-y
					if (R > L)
					{
						var ma = a[y]+(k-((y-l+1)*a[y]-(s[y]-s[l-1])))/L
						tmp = (s[r]-s[y])-(r-y)*ma+(y-l+1)*ma-(s[y]-s[l-1])
						ans = minOf(ans, tmp)
					}
				}
			}
			out.println(ans)
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