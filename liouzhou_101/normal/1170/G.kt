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
			
			var v = Array<TreeMap<Int, Int>>(n+1, {x->TreeMap<Int, Int>()})
			var deg = Array<Int>(n+1, {x->0})
			fun addEdge(x: Int, y: Int)
			{
				v[x].set(y, (v[x].get(y) ?: 0)+1)
				deg[x] ++
			}
			fun removeEdge(x: Int, y: Int)
			{
                v[x].set(y, v[x].get(y)!!-1)
				if (v[x][y] == 0) v[x].remove(y)
			}
			
			var ret = ArrayList<ArrayList<Int>>()
			
			for (i in 1..m)
			{
				var x = `in`.nextInt()
				var y = `in`.nextInt()
				if (x == y)
				{
					ret.add(arrayOf(x, x).toCollection(ArrayList()))
				}
				else
				{
					addEdge(x, y)
					addEdge(y, x)
				}
			}
			
			for (i in 1..n)
			{
				if (deg[i]%2 == 1)
				{
					out.println("NO")
					return
				}
			}
			
			var u = Array<Int>(n+1, {x -> 0})
			
			for (i in 1..n)
			{
				while (v[i].size > 0)
				{
					var x = i
					var q = Stack<Int>()
					q.push(x)
					u[x] = 1
					while (v[x].size > 0)
					{
						var y = v[x].firstKey()
						removeEdge(x, y)
						removeEdge(y, x)
						if (u[y] == 1)
						{
							var path = ArrayList<Int>()
							path.add(y)
							while (true)
							{
								var z = q.pop()
								path.add(z)
								u[z] = 0
								if (z == y) break
							}
							ret.add(path)
						}
						q.push(y)
						u[y] = 1
						x = y
					}
				}
			}
			
			out.println("YES")
			out.println(ret.size)
			for (path in ret)
			{
				out.print(path.size.toString()+" ")
				out.println(path.joinToString(" "))
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