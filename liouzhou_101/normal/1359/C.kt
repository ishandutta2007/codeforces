import java.util.*
import java.io.*

val MOD = 998244353

fun main(args: Array<String>)
{
	Thread(null, Main(), "whatever", 1 shl 28).start()
}

class Main : Runnable
{

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

	internal class TaskD
	{
		fun solve(testNumber: Int, `in`: InputReader, out: PrintWriter)
		{
			val INF = 4000000000000000000L
			val dx = intArrayOf(-1, 1, 0, 0)
			val dy = intArrayOf(0, 0, -1, 1)
 
			var h = `in`.nextLong()
			var c = `in`.nextLong()
			var t = `in`.nextLong()
			if (t == h) return out.println(1)
			if (t*2 <= h+c) return out.println(2)
			
			var k = (h-t)/(2*t-h-c)
			var tmp = ArrayList<LongArray>()
			for (i in k-2..k+2)
			{
				if (i >= 0)
				{
					var a = (i+1)*h+i*c
					var b = 2*i+1
					var d = gcd(a, b)
					a /= d
					b /= d
					a = Math.abs(a-b*t)
					tmp.add(longArrayOf(a, b, i))
				}
			}
			var choose = 0
			for (i in 1..tmp.size-1)
			{
				var a = tmp[choose][0]
				var b = tmp[choose][1]
				var c = tmp[i][0]
				var d = tmp[i][1]
				if (c*b < a*d) choose = i
			}
 
			out.println(tmp[choose][2]*2+1)
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

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a%b)

fun power(a: Long, b: Long, p: Long): Long
{
	if (b == 0L) return 1L
	var t = power(a, b/2, p)
	t = t*t%p
	if (b%2 == 1L) t = t*a%p
	return t
}

var factorial = arrayOf<ModInt>()
var invFactorial = arrayOf<ModInt>()

fun prepareFactorials(n: Int)
{
	factorial = Array<ModInt>(n+1, {0.toModInt()})
	invFactorial = Array<ModInt>(n+1, {0.toModInt()})
	factorial[0] = 1.toModInt()
	for (i in 1..n) factorial[i] = factorial[i-1]*i.toModInt()
	invFactorial[n] = factorial[n].inverse()
	for (i in n-1 downTo 0) invFactorial[i] = invFactorial[i+1]*(i+1).toModInt()
}

fun choose(n: Int, m: Int): ModInt
{
	if (m < 0 || m > n) return 0.toModInt()
	return factorial[n]*invFactorial[m]*invFactorial[n-m]
}

class ModInt
{
	var x: Int

	constructor (value: Int = 0)
	{
		x = value
	}
	constructor (modInt: ModInt)
	{
		x = modInt.x
	}

	operator fun unaryPlus() = ModInt(x)
	operator fun unaryMinus() = if (x != 0) ModInt(MOD-x) else ModInt(0)
	operator fun inc() = if (x == MOD-1) ModInt(0) else ModInt(x+1)
	operator fun dec() = if (x == 0) ModInt(MOD-1) else ModInt(x-1)

	operator fun plus(rhs: ModInt): ModInt
	{
		var c = x+rhs.x
		if (c >= MOD) c -= MOD
		return ModInt(c)
	}
	operator fun minus(rhs: ModInt): ModInt
	{
		var c = x-rhs.x
		if (c < 0) c += MOD
		return ModInt(c)
	}
	operator fun times(rhs: ModInt): ModInt
	{
		return ModInt((x.toLong()*rhs.x%MOD).toInt())
	}

	fun toInt() = this.x
	override fun toString() = this.x.toString()
	fun power(e: Int): ModInt
	{
		var ret = ModInt(1)
		var exp = e
		var base = ModInt(x)
		while (exp != 0)
		{
			if (exp and 1 == 1) ret *= base
			exp = exp shr 1
			base *= base
		}
		return ret
	}
	fun inverse() = power(MOD-2)
}

fun Int.toModInt() = ModInt(this)