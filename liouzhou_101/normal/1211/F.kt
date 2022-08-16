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
			
			fun calc(x: Char): Int
			{
				if (x == 'k') return 0
				if (x == 'o') return 1
				if (x == 't') return 2
				if (x == 'l') return 3
				if (x == 'i') return 4
				if (x == 'n') return 5
				return -1
			}
			
			var v = Array<TreeMap<Int, Int>>(6, {TreeMap<Int, Int>()})
			var w = Array<TreeMap<Int, Int>>(6, {TreeMap<Int, Int>()})
			
			for (i in 1..n)
			{
				var s = `in`.next()
				var x = calc(s[0])
				var y = calc(s[s.length-1])
				v[x].set(i, (y+1)%6)
				w[x].set(i, (y+1)%6)
			}
			
			var path = Array<ArrayList<Int>>(6, {ArrayList<Int>()})
			var b = Array<Int>(6, {0})
			
			for (i in 0..5)
			{
				var x = i
				while (v[x].size > 0)
				{
					var id = v[x].firstKey()
					var y = v[x][id]!!
					v[x].remove(id)
					path[i].add(id)
					x = y
				}
			}
			
			fun dfs(x: Int)
			{
				b[x] = 1
				var cur = x
				for (s in path[x])
				{
					out.print("$s ")
					cur = w[cur][s]!!
					if (b[cur] == 0) dfs(cur)
				}
			}
			
			dfs(0)
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