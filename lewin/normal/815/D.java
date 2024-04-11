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
import java.util.TreeSet;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int p = in.nextInt(), q = in.nextInt(), r = in.nextInt();
            TaskD.Cube[] cs = new TaskD.Cube[3 * n];
            for (int i = 0; i < n; i++) {
                int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
                cs[3 * i + 0] = new TaskD.Cube(a, b, r);
                cs[3 * i + 1] = new TaskD.Cube(a, q, c);
                cs[3 * i + 2] = new TaskD.Cube(p, b, c);
            }
            Arrays.sort(cs, Comparator.comparingInt(x -> -x.a));
            int[] vals = new int[q + 1];
            TreeSet<Integer> ts = new TreeSet<>();
            ts.add(0);
            ts.add(q);
            vals[0] = r + 1;
            long sum = 1l * q * r;
            long ans = 0;
            long last = p;
            for (TaskD.Cube c : cs) {
                ans += (last - c.a) * sum;
                last = c.a;

                int pos = c.b;
                int val = c.c;

                int lastv = vals[ts.ceiling(pos)];
                int lastp = pos;
                if (lastv >= val) continue;
                while (true) {
                    int k = ts.floor(pos);
                    sum -= 1L * (val - lastv) * (lastp - k);
                    lastp = k;
                    lastv = vals[k];
                    if (vals[k] > val) break;
                    ts.remove(k);
                }
                ts.add(pos);
                vals[pos] = val;
            }
            ans += last * sum;
            out.println(ans);
        }

        static class Cube {
            public int a;
            public int b;
            public int c;

            public Cube(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
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

        public void println(long i) {
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}