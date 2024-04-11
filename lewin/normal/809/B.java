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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public boolean LOCAL = false;
        public InputReader in;
        public OutputWriter out;
        public int[] pos;
        public int n;
        public int k;

        public boolean ask(int x, int y) {
            if (LOCAL) return __ask__(x, y);
            out.printf("1 %d %d\n", x, y);
            out.flush();
            return in.next().equals("TAK");
        }

        public boolean __ask__(int a, int b) {
            int x = n, y = n;
            for (int e : pos) {
                x = Math.min(x, Math.abs(e - a));
                y = Math.min(y, Math.abs(e - b));
            }
            return x <= y;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;

            n = in.nextInt();
            k = in.nextInt();
            if (LOCAL) {
                pos = new int[k];
                for (int i = 0; i < k; i++) {
                    pos[i] = (int) (Math.random() * n);
//                pos[i] = in.nextInt();
                }
            }
            int b = find(1, n, 0);

            int x = find(b + 1, n, 1);
            if (x == -1) x = find(1, b - 1, 2);

            out.println(2 + " " + b + " " + x);
            if (LOCAL) {
                boolean f1 = false, f2 = false;
                for (int e : pos) {
                    if (e == b) f1 = true;
                    if (e == x) f2 = true;
                }
                if (b == x || !f1 || !f2) {
                    out.println("FAIL");
                    out.println(pos[0] + " " + pos[1]);
                }
            }
            out.flush();
        }

        public int find(int from, int to, int mode) {
            if (from > to) return -1;
            int lo = from, hi = to;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (ask(mid, mid + 1)) hi = mid;
                else lo = mid + 1;
            }
            if (mode == 0) return lo;
            if (mode == 1 && lo == n) return ask(n, n - 1) ? lo : -1;
            if (mode == 1 && lo == from) return ask(from, from - 1) ? lo : -1;
            if (mode == 2 && lo == 1) return ask(1, 2) ? lo : -1;
            if (mode == 2 && lo == to) return ask(to, to + 1) ? lo : -1;
            return lo;
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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }

    }
}