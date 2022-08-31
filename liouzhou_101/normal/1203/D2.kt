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
			var s = `in`.next()
			var t = `in`.next()
			var n = s.length
			var m = t.length
			
			var L = Array<Int>(m+2, {_ -> -1})
			var j = 0
			for (i in 0..n-1)
			{
				if (j < m && s[i] == t[j])
				{
					L[j+1] = i
					j ++
				}
			}
			
			var R = Array<Int>(m+2, {_ -> n})
			j = m-1
			for (i in n-1 downTo 0)
			{
				if (j >= 0 && s[i] == t[j])
				{
					R[j+1] = i
					j --
				}
			}
			
			var ans = 0
			for (j in 0..m)
			{
				ans = maxOf(ans, R[j+1]-L[j]-1)
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