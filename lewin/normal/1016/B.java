import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
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
        BSegmentOccurrences solver = new BSegmentOccurrences();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSegmentOccurrences {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
            String s = in.next(), t = in.next();
            List<Integer> occ = ZFunction.findAll(s, t);
            int[] count = new int[n + 1];
            for (int x : occ) count[x + 1]++;
            for (int i = 1; i <= n; i++) count[i] += count[i - 1];
            while (q-- > 0) {
                int l = in.nextInt(), r = Math.max(0, in.nextInt() - m + 1);
                out.println(Math.max(0, count[r] - count[l - 1]));
            }
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

        public void println(int i) {
            writer.println(i);
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

    static class ZFunction {
        public static int[] zFunction(String s) {
            int[] z = new int[s.length()];
            for (int i = 1, l = 0, r = 0; i < z.length; ++i) {
                if (i <= r)
                    z[i] = Math.min(r - i + 1, z[i - l]);
                while (i + z[i] < z.length && s.charAt(z[i]) == s.charAt(i + z[i]))
                    ++z[i];
                if (r < i + z[i] - 1) {
                    l = i;
                    r = i + z[i] - 1;
                }
            }
            return z;
        }

        public static List<Integer> findAll(String s, String pattern) {
            int[] z = zFunction(pattern + "\0" + s);
            List<Integer> res = new ArrayList<>();
            for (int i = pattern.length() + 1; i < z.length; i++)
                if (z[i] == pattern.length())
                    res.add(i - pattern.length() - 1);
            return res;
        }

    }
}