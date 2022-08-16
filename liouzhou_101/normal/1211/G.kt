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
			val MAXK = 18
			
			var test = `in`.nextInt()
			for (tests in 1..test)
			{
				var n = `in`.nextInt()
				var v = Array<ArrayList<Int>>(n+1, {ArrayList<Int>()})
				var c = Array<Int>(n+1, {0})
				var d = Array<Int>(n+1, {0})
                
				for (i in 1..n) c[i] = `in`.nextInt()
				for (i in 1..n) d[i] = `in`.nextInt()
				
				for (i in 1..n-1)
				{
					var x = `in`.nextInt()
					var y = `in`.nextInt()
					v[x].add(y)
					v[y].add(x)
				}
				
				var a = Array<Int>(n+1, {0})
				
				
				
				var root = 0
				for (i in 1..n)
				{
					if (c[i] != d[i])
					{
						a[i] = 1
						root = i
					}
				}
				
				if (root == 0)
				{
					out.println("Yes")
					out.println(0)
					continue
				}
				
				var rr = 0
				fun dfs2(x: Int, p: Int)
				{
					for (y in v[x])
					{
						if (y == p) continue
						dfs2(y, x)
					}
					if (rr == 0 && a[x] == 1) rr = x
				}
				
				dfs2(root, 0)
				root = rr
				
				var flag = 0
				var q = Stack<Int>()
				
				
				fun dfs(x: Int, p: Int)
				{
					q.push(x)
					var cnt = 0
					for (y in v[x])
					{
						if (y == p) continue
						dfs(y, x)
						if (a[y] > 0)
						{
							cnt ++
							if (cnt >= 2)
							{
							    flag = 1
							}
						}
						a[x] += a[y]
					}
					if (a[x] == 0) q.pop()
				}
				
				dfs(root, 0)
				
				if (flag == 1)
				{
					out.println("No")
					continue
				}
				
				
				var x = root
				var y = q.pop()
				
				var path = ArrayList<Int>()
				path.add(y)
				while (q.size > 0) path.add(q.pop())
				
				
				flag = 0
				for (i in 0..path.size-1)
					if (d[path[i]] != c[path[(i+1)%path.size]]) flag = 1
				if (flag == 0)
				{
					out.println("Yes")
					out.println(path.size)
					for (x in path)
						out.print("$x ")
					out.println()
					continue
				}
				
				
				path.reverse()
				flag = 0
				for (i in 0..path.size-1)
					if (d[path[i]] != c[path[(i+1)%path.size]]) flag = 1
				if (flag == 0)
				{
					out.println("Yes")
					out.println(path.size)
					for (x in path)
						out.print("$x ")
					out.println()
					continue
				}
				
				
				out.println("No")
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