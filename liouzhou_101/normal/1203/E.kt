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
			val INF = 1000000000
		
			var n = `in`.nextInt()
			var a = Array<Int>(n+1, {0})
			for (i in 1..n) a[i] = `in`.nextInt()
			a.sort(1, n+1)
			var F = Array<Array<Int>>(n+1, {Array<Int>(4, {0})})
			
			for (i in 1..n)
			{
				for (j in 0..3)
				{
					var x = maxOf(a[i]+(if (j == 0) -INF else j-2), 0)
					F[i][j] = F[i-1][j]
					for (k in 0..3)
					{
						var y = maxOf(a[i-1]+(if (k == 0) -INF else k-2), 0)
						if (y < x)
							F[i][j] = maxOf(F[i][j], F[i-1][k]+(if (j == 0) 0 else 1))
					}
				}
			}
			
			out.println(F[n].max())
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