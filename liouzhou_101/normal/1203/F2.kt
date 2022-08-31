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
			var r = `in`.nextInt()
			var a = Array<Pair<Int, Int>>(n, {Pair(`in`.nextInt(), `in`.nextInt())})
			a.sortWith(compareBy({if (it.second > 0) 1 else 2}, {if (it.second > 0) it.first else -it.first-it.second}))
			
			var F = Array<Int>(60010, {-INF})
			F[r] = 0
			for ((x, y) in a)
			{
				if (y > 0)
				{
					for (i in 60000-y downTo x)
						F[i+y] = maxOf(F[i+y], F[i]+1)
				}
				else
				{
					for (i in maxOf(x, -y)..60000)
						F[i+y] = maxOf(F[i+y], F[i]+1)
				}
			}
			
			out.println(F.max())
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