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
import java.util.TreeSet;
import java.util.ArrayList;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        int abs(int x) {
            return x < 0 ? -x : x;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int cl = in.nextInt(), ce = in.nextInt(), v = in.nextInt();
            TreeSet<Integer> ts1 = new TreeSet<>();
            TreeSet<Integer> ts2 = new TreeSet<>();
            for (int i = 0; i < cl; i++) ts1.add(in.nextInt());
            for (int i = 0; i < ce; i++) ts2.add(in.nextInt());

            int q = in.nextInt();
            while (q-- > 0) {
                int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
                if (x1 == x2) {
                    out.println(abs(y1 - y2));
                    continue;
                }

                int min = Integer.MAX_VALUE;
                ArrayList<Integer> tt = new ArrayList<>();
                tt.add(ts1.lower(y1));
                tt.add(ts1.higher(y1));
                tt.add(ts1.lower(y2));
                tt.add(ts1.higher(y2));
                for (Integer y : tt) {
                    if (y == null) continue;
                    int cost = abs(y - y1) + abs(y - y2) + abs(x2 - x1);
                    if (cost < min) {
                        min = cost;
                    }

                }

                tt = new ArrayList<>();
                tt.add(ts2.lower(y1));
                tt.add(ts2.higher(y1));
                tt.add(ts2.lower(y2));
                tt.add(ts2.higher(y2));
                for (Integer y : tt) {
                    if (y == null) continue;
                    int cost = abs(y - y1) + abs(y - y2) + (abs(x2 - x1) + v - 1) / v;
                    if (cost < min) {
                        min = cost;
                    }
                }
                out.println(min);
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}