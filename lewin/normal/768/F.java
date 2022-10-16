import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public int mod = 1000000007;
        public long[] fact;
        public long[] ifact;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int f = in.nextInt(), w = in.nextInt(), h = in.nextInt();
            if (w == 0) {
                out.println(1);
                return;
            }
            if (f == 0) {
                if (w > h) out.println(1);
                else out.println(0);
                return;
            }
            long[][] x = Factorials.getFIF(f + w + 1, mod);
            fact = x[0];
            ifact = x[1];
            // starts with f
            long num = 0, den = 0;
            for (int len = 1; len <= w + f; len++) {
                int needf = (len + 1) / 2;
                if (needf > f) break;
                int needw = len / 2;
                if (needw > w) break;
                long a1 = nways(f - needf, needf);
                den = (den + a1 * nways(w - needw, needw)) % mod;
                if (1L * needw * (h + 1) <= w)
                    num = (num + a1 * nways(w - needw * (h + 1), needw)) % mod;
            }
            // starts with w
            for (int len = 1; len <= w + f; len++) {
                int needw = (len + 1) / 2;
                if (needw > w) break;
                int needf = len / 2;
                if (needf > f) break;
                long a1 = nways(f - needf, needf);
                den = (den + a1 * nways(w - needw, needw)) % mod;
                if (1L * needw * (h + 1) <= w)
                    num = (num + a1 * nways(w - needw * (h + 1), needw)) % mod;
            }

            out.println(num * Utils.inv(den, mod) % mod);
        }

        public long nways(int i, int j) {
            if (i < 0) return 0;
            if (j == 0) {
                return i == 0 ? 1 : 0;
            }
            return fact[i + j - 1] * ifact[j - 1] % mod * ifact[i] % mod;
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

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class Utils {
        public static long inv(long N, long M) {
            long x = 0, lastx = 1, y = 1, lasty = 0, q, t, a = N, b = M;
            while (b != 0) {
                q = a / b;
                t = a % b;
                a = b;
                b = t;
                t = x;
                x = lastx - q * x;
                lastx = t;
                t = y;
                y = lasty - q * y;
                lasty = t;
            }
            return (lastx + M) % M;
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

        public void println(int i) {
            writer.println(i);
        }

    }

    static class Factorials {
        public static long[][] getFIF(int max, int mod) {
            long[] fact = new long[max];
            long[] ifact = new long[max];
            long[] inv = new long[max];
            inv[1] = 1;
            for (int i = 2; i < max; i++) {
                inv[i] = (mod - mod / i) * inv[mod % i] % mod;
            }
            fact[0] = 1;
            ifact[0] = 1;
            for (int i = 1; i < max; i++) {
                fact[i] = fact[i - 1] * i % mod;
                ifact[i] = ifact[i - 1] * inv[i] % mod;
            }
            return new long[][]{fact, ifact, inv};
        }

    }
}