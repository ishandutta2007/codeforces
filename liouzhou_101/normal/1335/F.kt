import java.util.*
import java.io.*

fun main() {
	Thread(null, Main(), "whatever", 1 shl 28).start()
}
 
class Main : Runnable {
	
	override fun run()
	{
		val inputStream = System.`in`
		val outputStream = System.out
		val `in` = InputReader(inputStream)
		val out = PrintWriter(outputStream)
		val solver = TaskD()
		var test = 1
		test = `in`.nextInt()
		for (t in 1..test)
		{
			solver.solve(t, `in`, out)
		}
		out.close()
	}
 
	internal class TaskD {
		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter) {
			val INF = 1000000000
			val dx = intArrayOf(-1, 1, 0, 0)
			val dy = intArrayOf(0, 0, -1, 1)
 
			var n = `in`.nextInt()
			var m = `in`.nextInt()
			var c = Array<String>(n, {`in`.next()})
			var g = Array<String>(n, {`in`.next()})
			var u = Array<IntArray>(n, {IntArray(m)})
			var tox = Array<IntArray>(n, {IntArray(m)})
			var toy = Array<IntArray>(n, {IntArray(m)})

			for (i in 0..n-1)
				for (j in 0..m-1)
				{
					var x = i
					var y = j
					if (g[x][y] == 'U') x -= 1
					else if (g[x][y] == 'D') x += 1
					else if (g[x][y] == 'L') y -= 1
					else if (g[x][y] == 'R') y += 1
					tox[i][j] = x
					toy[i][j] = y
				}

			var res = 0
			var cnt = 0
			for (i in 0..n-1)
			{
				for (j in 0..m-1)
				{
					if (u[i][j] != 0) continue

					var stamp = 1
					var x = i
					var y = j
					u[x][y] = stamp
					while (true)
					{
						var tx = x
						var ty = y
						x = tox[tx][ty]
						y = toy[tx][ty]
						stamp += 1
						if (u[x][y] != 0) break
						u[x][y] = stamp
					}
					var len = stamp-u[x][y]
					
					var pile = IntArray(len)
					fun go(x: Int, y: Int, z: Int): Unit
					{
						u[x][y] = -1
						if (c[x][y] == '0') pile[z] = 1
						for (k in 0..3)
						{
							var tx = x+dx[k]
							var ty = y+dy[k]
							if (0 <= tx && tx < n && 0 <= ty && ty < m && tox[tx][ty] == x && toy[tx][ty] == y && u[tx][ty] != -1)
							{
								go(tx, ty, (z+1)%len)
							}
						}
						return
					}

					go(x, y, 0)
					
					res += len
					for (k in 0..len-1) cnt += pile[k]
				}
			}
			out.println("$res $cnt")
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