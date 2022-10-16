import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long n = in.nextLong();
            long k = in.nextLong();
            k = (k + 1) / 2;
            while (k > 0 && n > 1) {
                if (BigInteger.valueOf(n).isProbablePrime(30)) {
                    n--;
                    k--;
                    continue;
                }
                long m = n;
                for (long i = 2; i * i * i <= m; i++) {
                    if (m % i == 0) {
                        while (m % i == 0) {
                            m /= i;
                        }
                        n -= n / i;
                    }
                }
                if (m > 1 && BigInteger.valueOf(m).isProbablePrime(30)) {
                    n -= n / m;
                    m = 1;
                }
                if (m > 1) {
                    long d = (long) Math.sqrt(m);
                    while (d * d > m) --d;
                    while (d * d < m) ++d;
                    if (d * d == m) {
                        n -= n / d;
                    } else {
                        d = getFactor(m);
                        n -= n / d;
                        n -= n / (m / d);
                    }
                }
                k--;
            }
            out.println(n % 1000000007);
        }

        private long getFactor(long n) {
            int start = 2;
            while (true) {
                long x = start;
                long y = start;
                long factor = 1;
                while (factor == 1) {
                    x = g(x, n);
                    y = g(g(y, n), n);
                    factor = Utils.gcd(Math.abs(x - y), n);
                }
                if (factor != n) {
                    return factor;
                }
                ++start;
            }
        }

        static long g(long x, long n) {
            return (mul(x, x, n) + 1) % n;
        }

        static long mul(long a, long b, long mod) {
            long ret = 0;
            while (b > 0) {
                if ((b & 1) == 1) {
                    ret += a;
                    if (ret >= mod) ret -= mod;
                }
                a += a;
                if (a >= mod) a -= mod;
                b >>= 1;
            }
            return ret;
        }

    }

    static class Utils {
        public static long gcd(long x, long y) {
            for (; x != 0; x ^= y, y ^= x, x ^= y, x %= y) ;
            return y;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}