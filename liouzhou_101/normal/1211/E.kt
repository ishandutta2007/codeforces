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
			var a = Array<Int>(n+1, {0})
			for (i in 1..n) a[i] = `in`.nextInt()
			
			var b = Array<Int>(n+1, {0})
			
			fun check(m: Int): Int
			{
				var c = Array<Int>(n+1, {0})
				var d = Array<Int>(n+1, {0})
				var x = ArrayList<Int>()
				var y = ArrayList<Int>()
				for (i in 1..n)
				{
					if (a[i] > m)
						b[i] = 2
					else
					{
						if (c[a[i]] == 0)
						{
							b[i] = 0
							c[a[i]] = i
							x.add(a[i])
						}
						else if (d[a[i]] == 0)
						{
							b[i] = 1
							d[a[i]] = i
							y.add(a[i])
						}
						else
							return 0
					}
				}
				if (x.size != m) return 0
				if (y.size != m) return 0
				for (i in 0..m-1)
					if (x[i] != y[i]) return 0
				return 1
			}
			
			var L = 1
			var R = n
			var ans = 0
			while (L <= R)
			{
				var m = (L+R)/2
				var ret = check(m)
				if (ret == 1)
				{
					ans = m
					L = m+1
				}
				else
				{
					R = m-1
				}
			}
			
			check(ans)
			for (i in 1..n)
			{
				if (b[i] == 0)
					out.print("R")
				else if (b[i] == 1)
					out.print("G")
				else if (b[i] == 2)
					out.print("B")
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