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
import java.util.Comparator;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        TaskB.Item[] c;
        long[] vv;
        int n;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            int x1 = in.nextInt(), x2 = in.nextInt();
            c = new TaskB.Item[n];
            for (int i = 0; i < n; i++) c[i] = new TaskB.Item(in.nextInt(), i + 1);
            Arrays.sort(c, Comparator.comparingInt(x -> x.x));
            vv = new long[n + 1];
            vv[n] = 0;
            for (int i = n - 1; i >= 0; i--) {
                vv[i] = 1L * c[i].x * (n - i);
                vv[i] = Math.max(vv[i], vv[i + 1]);
            }
            if (solve(x1, x2, false, out)) return;
            if (solve(x2, x1, true, out)) return;
            out.println("No");
        }

        boolean solve(int x1, int x2, boolean swap, OutputWriter out) {
            int lo = 0;
            for (int s1 = n - 1; s1 >= 1; s1--) {
                while (lo < n && 1L * c[lo].x * s1 < x1) lo++;
                if (lo + s1 > n) continue;
                if (vv[lo + s1] >= x2) {
                    out.println("Yes");
                    int j = lo + s1;
                    for (; j < n; j++) {
                        if (1L * c[j].x * (n - j) >= x2) {
                            break;
                        }
                    }

                    if (!swap) {
                        out.println(s1 + " " + (n - j));
                        for (int q = 0; q < s1; q++) {
                            out.print(c[lo + q].id + " ");
                        }
                        out.println();
                        for (; j < n; j++) {
                            out.print(c[j].id + " ");
                        }
                        out.println();
                    } else {
                        out.println((n - j) + " " + s1);
                        for (; j < n; j++) {
                            out.print(c[j].id + " ");
                        }
                        out.println();
                        for (int q = 0; q < s1; q++) {
                            out.print(c[lo + q].id + " ");
                        }
                        out.println();
                    }

                    return true;
                }
            }
            return false;

        }

        static class Item {
            public int x;
            public int id;

            public Item(int x, int id) {
                this.x = x;
                this.id = id;
            }

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

        public void println() {
            writer.println();
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}