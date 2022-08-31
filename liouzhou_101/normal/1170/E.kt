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
			var n = `in`.nextInt()
			var m = `in`.nextInt()
			var a = Array<Int>(n+1, {x->0})
			var s = Array<Int>(n+1, {x->0})
			for (i in 1..n)
			{
				a[i] = `in`.nextInt()
				s[i] = s[i-1]+a[i]
			}
			var q = `in`.nextInt()
			for (tests in 1..q)
			{
				var len = `in`.nextInt()
				var b = Array<Int>(len+2, {x->0})
				for (i in 1..len)
				{
					b[i] = `in`.nextInt()
				}
				b[len+1] = m+1
				var cur = 0
				for (i in 1..len+1)
				{
					if (cur < s.size)
					{
						cur = s.binarySearch(s[cur]+b[i]-b[i-1])
						if (cur < 0) cur = -cur-1
						cur --
					}
				}
				if (cur < n)
					out.println("NO")
				else
					out.println("YES")
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
 
	}
}