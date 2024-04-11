import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskE {
        public long mod = (5 << 25) + 1;
        public int len;
        public int levels;
        public long gen;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();
            levels = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
            len = 1 << levels;
            int ww = 25;
            gen = 243;
            while (ww-- > levels) {
                gen = gen * gen % mod;
            }
            long[] arr1 = new long[len];
            long[] arr2 = new long[len];
            for (int i = 0; i < n; i++) {
                if (s[i] == 'V') arr1[i] = 1;
                else if (s[i] == 'K') arr2[n - i] = 1;
            }
            transform(arr1, gen);
            transform(arr2, gen);
            long scale = inv(len, mod);
            for (int i = 0; i < len; i++)
                arr1[i] = arr1[i] * arr2[i] % mod * scale % mod;
            transform(arr1, inv(gen, mod));

            boolean[] bad = new boolean[n + 1];
            for (int i = 0; i < arr1.length; i++) {
                if (arr1[i] != 0) bad[Math.abs(i - n)] = true;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = i; !bad[i] && j <= n; j += i) {
                    bad[i] |= bad[j];
                }
            }
            int c = 0;
            for (int i = 1; i <= n; i++) if (!bad[i]) c++;
            out.println(c);
            for (int i = 1; i <= n; i++) {
                if (!bad[i])
                    out.print(i + " ");
            }
            out.println();
        }

        public void transform(long[] a, long gen) {
            for (int i = 0; i < len; i++) {
                int j = Integer.reverse(i) >>> (32 - levels);
                if (j < i) {
                    long t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }

            long[] w = new long[levels + 1];
            w[levels] = gen;
            for (int i = levels - 1; i >= 0; i--) {
                w[i] = w[i + 1] * w[i + 1] % mod;
            }
            for (int l = 1, hs = 1; (1 << l) <= len; l++, hs <<= 1) {
                long[] fr = new long[hs];
                fr[0] = 1;
                for (int j = 1; j < hs; j++) fr[j] = fr[j - 1] * w[l] % mod;
                for (int i = 0; i < len; i += (1 << l)) {
                    for (int j = i; j < i + hs; j++) {
                        long tre = a[j + hs] * fr[j - i] % mod;
                        a[j + hs] = a[j] + mod - tre;
                        if (a[j + hs] >= mod) a[j + hs] -= mod;
                        a[j] += tre;
                        if (a[j] >= mod) a[j] -= mod;
                    }
                }
            }
        }

        public long inv(long N, long M) {
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
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

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}