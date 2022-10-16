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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[] g(char[] x) {
            int[] r = new int[x.length + 1];
            for (int i = 1; i <= x.length; i++) {
                if (x[i - 1] != 'A') r[i] = 0;
                else {
                    r[i] = r[i - 1] + 1;
                }
            }
            return r;
        }

        int[] p(char[] x) {
            int[] r = new int[x.length + 1];
            for (int i = 1; i <= x.length; i++) {
                r[i] = r[i - 1] + (x[i - 1] == 'A' ? 0 : 1);
            }
            return r;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] s = in.next().toCharArray();
            char[] t = in.next().toCharArray();
            int[] a1 = p(s), a2 = p(t);
            int[] r1 = g(s), r2 = g(t);
            int q = in.nextInt();
            while (q-- > 0) {
                int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
                int c1 = a1[b] - a1[a - 1], c2 = a2[d] - a2[c - 1];
                int x1 = Math.min(r1[b], b - a + 1), x2 = Math.min(r2[d], d - c + 1);
                out.print(can(c1, x1, c2, x2) ? "1" : "0");
            }
            out.println();
        }

        boolean can(int c1, int x1, int c2, int x2) {
            if (x1 < x2) return false;
            if (c1 == 0 && c2 == 0 && (x1 - x2) % 3 != 0) return false;
            if (c1 == 0 && c2 > 0) {
                if (x1 == x2) return false;
                c1 += 2;
            } else if ((x1 - x2) % 3 != 0) {
                c1 += 2;
            }

            return c1 <= c2 && (c1 % 2 == c2 % 2);
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

    }
}