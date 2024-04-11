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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BTheHat solver = new BTheHat();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTheHat {
        InputReader in;
        OutputWriter out;
        int n;

        int ask(int student) {
            student %= n;
            out.println("? " + (student + 1));
            out.flush();
            return in.nextInt();
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;

            n = in.nextInt();
            int a = ask(0), b = ask(n / 2);
            if ((a + b) % 2 != 0) {
                out.println("! -1");
                out.flush();
                return;
            }
            if (a == b) {
                out.println("! 1");
                out.flush();
                return;
            }

            int lo = 0, hi = n / 2;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int f1 = ask(mid), f2 = ask(mid + n / 2);
                if (f1 == f2) {
                    out.println("! " + (mid + 1));
                    return;
                }
                if ((a > b) == (f1 > f2)) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            out.println("! " + (lo + 1));
            out.flush();
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

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }

    }
}