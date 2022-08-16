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
			val INF = 1000000000
			
			var n = `in`.nextInt()
			var a = `in`.nextInt()
			var b = `in`.nextInt()
			var k = `in`.nextInt()
			
			var u = Array<Int>(1000010, {0})
			for (i in 1..n)
			{
				u[`in`.nextInt()] ++
			}
			
			var F = Array<Array<Int>>(21, {Array<Int>(n+1, {-INF})})
			var ans = 0
			
			for (i in 1..1000000)
			{
				if (u[i] == 0) continue
				var v = ArrayList<Int>()
				var j = i
				var m = 0
				while (j <= 1000000)
				{
					m += u[j]
					v.add(u[j])
					u[j] = 0
					j *= k
				}
				var len = v.size
				F[0][0] = 0
				for (x in 1..len)
				{
					for (y in m downTo 0)
					{
						F[x][y] = -INF
					}
					var y = v[x-1]
					for (z in 0..y) F[x][y] = 0
					for (z in 0..y/b)
					{
						if (z*a <= m)
						{
							F[x][y-z*b] = maxOf(F[x][y-z*b], F[x-1][z*a]+z)
						}
					}
					for (y in m-1 downTo 0)
						F[x][y] = maxOf(F[x][y], F[x][y+1])
				}
				ans += F[len][0]
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