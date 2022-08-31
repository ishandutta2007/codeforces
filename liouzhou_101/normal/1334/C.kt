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
			var a = LongArray(n)
			var b = LongArray(n)

			var sum = 0L
			for (i in 0..n-1)
			{
				a[i] = `in`.nextLong()
				b[i] = `in`.nextLong()
				sum += a[i]
			}

			for (i in 0..n-1)
			{
				b[i] = Math.min(b[i], a[(i+1)%n])
				sum -= b[i]
			}

			sum += b.min()!!

			out.println(sum)
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