import java.util.*
import java.io.*
//import kotlin.math.*
 
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
			var n = `in`.nextInt()
			var k = `in`.nextInt().toLong()
			var a = Array<Int>(n+1, {0})
			var b = Array<Int>(n+1, {0})
			var c = Array<Int>(n+1, {0})
			var ans = 0L
			var cnt = 0L
			var bound = 0L
			for (i in 1..n)
			{
				a[i] = `in`.nextInt()
				b[i] = `in`.nextInt()
				c[i] = `in`.nextInt()
				bound += b[i]
				ans += a[i].toLong()*c[i]
				cnt += a[i]
				b[i] -= a[i]
			}
			if (bound < k)
			{
				out.println(-1)
				return
			}
			if (cnt > k)
			{
				out.println(-1)
				return
			}
			var p = Array<Int>(n, {x -> x+1})
			p.sortWith(compareBy({c[it]}))
			k -= cnt
			for (x in p)
			{
				ans += minOf(k, b[x].toLong())*c[x]
				k -= minOf(k, b[x].toLong())
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