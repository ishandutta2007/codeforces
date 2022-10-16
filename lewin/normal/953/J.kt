import java.io.*
import java.util.Comparator
import java.util.InputMismatchException
import java.util.TreeSet

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
object programkt {
    @JvmStatic
    fun main(args: Array<String>) {
        val inputStream = System.`in`
        val outputStream = System.out
        val `in` = InputReader(inputStream)
        val out = OutputWriter(outputStream)
        val solver = Segments()
        solver.solve(1, `in`, out)
        out.close()
    }

    internal class Segments {
        fun solve(testNumber: Int, `in`: InputReader, out: OutputWriter) {
            var n = `in`.nextInt()
            val ts = TreeSet(Comparator.comparingInt<Interval> { x -> x.l })
            while (n-- > 0) {
                val l = `in`.nextInt()
                val r = `in`.nextInt()
                var add = Segments.Interval(l, r)
                while (true) {
                    val qq = ts.floor(add)
                    if (qq == null || qq.r < add.l) break
                    ts.remove(qq)
                    add = Segments.Interval(Math.min(qq.l, add.l), Math.max(qq.r, add.r))
                }
                while (true) {
                    val qq = ts.ceiling(add)
                    if (qq == null || qq.l > add.r) break
                    ts.remove(qq)
                    add = Segments.Interval(Math.min(qq.l, add.l), Math.max(qq.r, add.r))
                }
                ts.add(add)
                out.println(ts.size)
            }
        }

        internal class Interval(var l: Int, var r: Int) {


            override fun toString(): String {
                return "Interval{" +
                        "l=" + l +
                        ", r=" + r +
                        '}'
            }

        }

    }

    internal class InputReader(private val stream: InputStream) {
        private val buf = ByteArray(1 shl 16)
        private var curChar: Int = 0
        private var numChars: Int = 0

        fun read(): Int {
            if (this.numChars == -1) {
                throw InputMismatchException()
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0

                    try {
                        this.numChars = this.stream.read(this.buf)
                    } catch (var2: IOException) {
                        throw InputMismatchException()
                    }

                    if (this.numChars <= 0) {
                        return -1
                    }
                }

                return this.buf[this.curChar++].toInt()
            }
        }

        fun nextInt(): Int {
            var c: Int
            c = this.read()
            while (isSpaceChar(c)) {
                c = this.read()
            }

            var sgn: Byte = 1
            if (c == 45) {
                sgn = -1
                c = this.read()
            }

            var res = 0

            while (c >= 48 && c <= 57) {
                res *= 10
                res += c - 48
                c = this.read()
                if (isSpaceChar(c)) {
                    return res * sgn
                }
            }

            throw InputMismatchException()
        }

        companion object {

            fun isSpaceChar(c: Int): Boolean {
                return c == 32 || c == 10 || c == 13 || c == 9 || c == -1
            }
        }

    }

    internal class OutputWriter {
        private val writer: PrintWriter

        constructor(outputStream: OutputStream) {
            writer = PrintWriter(BufferedWriter(OutputStreamWriter(outputStream)))
        }

        constructor(writer: Writer) {
            this.writer = PrintWriter(writer)
        }

        fun close() {
            writer.close()
        }

        fun println(i: Int) {
            writer.println(i)
        }

    }
}