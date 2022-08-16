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
			val INF = 1000000000
			var s = Array<IntArray>(2010, {IntArray(27, {-INF})})
 
			var tests = `in`.nextInt()
			for (test in 1..tests)
			{
				var n = `in`.nextInt()
				var a = IntArray(n, {`in`.nextInt()})
				var v = Array<ArrayList<Int>>(27, {arrayListOf()})
				for (i in 1..n)
				{
					for (j in 1..26)
					{
						s[i][j] = s[i-1][j]
					}
					s[i][a[i-1]] += 1
					v[a[i-1]].add(i)
				}
				var res = 0
				for (j in 1..26)
				{
					var len = v[j].size
					for (k in 0..len/2)
					{
						var x = 0
						var y = 0
						if (k == 0)
						{
							x = 0
							y = n+1
						}
						else
						{
							x = v[j][k-1]
							y = v[j][len-k]
						}
						for (i in 1..26)
						{
							res = Math.max(res, k*2+s[y-1][i]-s[x][i])
						}
					}
				}
				out.println(res)
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