import java.util.*
import java.io.*
 
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
			var a = Array<Int>(n, {x->0})
			for (i in 0..n-1)
			{
				a[i] = `in`.nextInt()
			}
			var m = 0
			for (i in 0..n-1)
			{
				if (a[i] == -1) m ++
			}
			var ret = Array<ArrayList<Int>>(m+2, {_ -> ArrayList<Int>()})
			var L = IntArray(m+2, {x -> x-1})
			var R = IntArray(m+2, {x -> x+1})
			var id = 1
			for (x in a)
			{
				if (x == -1)
				{
					R[L[id]] = R[id]
					L[R[id]] = L[id]
				}
				else
				{
					ret[id].add(x)
				}
				id = R[id]
				if (id > m) id = R[0]
			}
			out.println(m)
			for (i in 1..m)
			{
				out.print(ret[i].size)
				for (x in ret[i])
					out.print(" $x")
				out.println()
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