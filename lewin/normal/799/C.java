import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public int[] bc;
        public int[] bd;
        public int[] ec;
        public int[] ed;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int c = in.nextInt();
            int d = in.nextInt();
            int mxn = 100010;
            bc = new int[mxn];
            bd = new int[mxn];
            ec = new int[mxn];
            ed = new int[mxn];
            Arrays.fill(bc, -(1 << 29));
            Arrays.fill(bd, -(1 << 29));
            int ret = 0;
            for (int i = 0; i < n; i++) {
                int b = in.nextInt();
                int x = in.nextInt();
                char e = in.next().charAt(0);
                if (e == 'C') {
                    if (x + x <= c) {
                        ret = Math.max(ret, bc[x] + b);
                    }
                    bc[x] = Math.max(bc[x], b);
                } else {
                    if (x + x <= d) {
                        ret = Math.max(ret, bd[x] + b);
                    }
                    bd[x] = Math.max(bd[x], b);
                }
            }
            ec[0] = bc[0];
            ed[0] = bd[0];
            for (int i = 1; i < mxn; i++) {
                ec[i] = bc[i];
                ed[i] = bd[i];
                bc[i] = Math.max(bc[i - 1], bc[i]);
                bd[i] = Math.max(bd[i - 1], bd[i]);
            }

            ret = Math.max(ret, bc[c] + bd[d]);
            for (int i = 1; i < mxn; i++) {
                if (i <= c) {
                    ret = Math.max(ret, ec[i] + bc[Math.min(i - 1, c - i)]);
                }
                if (i <= d) {
                    ret = Math.max(ret, ed[i] + bd[Math.min(i - 1, d - i)]);
                }
            }
            out.println(ret);
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