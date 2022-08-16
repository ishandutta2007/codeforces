import java.util.*
import java.io.*
//import kotlin.math.*

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

			var tests = `in`.nextInt()
			for (test in 1..tests)
			{
				var n = `in`.nextInt()
				var a = Array<Int>(n+1, {0})
				for (i in 1..n)
				{
					var x = `in`.nextInt()
					a[x] += 1
				}
				var most = 0
				var cnt = 0
				for (i in 1..n)
				{
					most = Math.max(most, a[i])
					if (a[i] > 0) cnt += 1
				}
				if (most == cnt)
				{
					out.println(most-1)
				}
				else
				{
					out.println(Math.min(most, cnt))
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