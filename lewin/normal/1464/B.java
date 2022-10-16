import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.stream.LongStream;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BGrimeZoo solver = new BGrimeZoo();
        solver.solve(1, in, out);
        out.close();
    }

    static class BGrimeZoo {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] c = in.next().toCharArray();
            long x = in.nextInt(), y = in.nextInt();
            int n = c.length;
            if (x > y) {
                long t = x;
                x = y;
                y = t;
                for (int i = 0; i < n; i++) {
                    if (c[i] != '?') {
                        c[i] = (char) (c[i] ^ '1' ^ '0');
                    }
                }
            }
            int c0 = 0, c1 = 0;
            for (int i = 0; i < n; i++) {
                if (c[i] == '0') c0++;
                else if (c[i] == '1') c1++;
            }

            int p0 = 0, p1 = 0;
            long[] arr = new long[n], brr = new long[n];
            int id = 0;
            long ret = 0;
            for (int i = 0; i < n; i++) {
                if (c[i] == '0') {
                    p0++;
                    ret += p1 * y;
                } else if (c[i] == '1') {
                    p1++;
                    ret += p0 * x;
                }

                if (c[i] == '?') {
                    arr[id] = p1 * y + (c1 - p1) * x;
                    brr[id] = p0 * x + (c0 - p0) * y;
                    id++;
                }
            }
            arr = Arrays.copyOf(arr, id);
            brr = Arrays.copyOf(brr, id);
            long sum = AUtils.sum(brr);
            long add = sum;
            for (int j = 0; j < id; j++) {
                sum -= brr[j];
                sum += arr[j];
                add = Math.min(add, sum + 1l * (j + 1) * (id - 1 - j) * x);
            }

            out.println(ret + add);

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

    static class AUtils {
        public static long sum(long[] arr) {
            return Arrays.stream(arr).reduce(0, Long::sum);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new UnknownError();
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