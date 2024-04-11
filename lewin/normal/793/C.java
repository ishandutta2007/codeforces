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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int x1 = 2 * in.nextInt(), y1 = 2 * in.nextInt(), x2 = 2 * in.nextInt(), y2 = 2 * in.nextInt();
            int cx = (x1 + x2) / 2, cy = (y1 + y2) / 2;
            x1 -= cx;
            x2 -= cx;
            y1 -= cy;
            y2 -= cy;

            double r1 = 0, r2 = 1L << 60;
            for (int i = 0; i < n; i++) {
                int rx = 2 * in.nextInt(), ry = 2 * in.nextInt(), vx = 2 * in.nextInt(), vy = 2 * in.nextInt();
                rx -= cx;
                ry -= cy;

                if (vx < 0) {
                    rx = -rx;
                    vx = -vx;
                }
                if (vy < 0) {
                    ry = -ry;
                    vy = -vy;
                }

                double[] xint = get(rx, vx, x1, x2);
                double[] yint = get(ry, vy, y1, y2);

                double[] e = new double[]{Math.max(xint[0], yint[0]), Math.min(xint[1], yint[1])};
                if (e[0] > e[1] || e[1] < 0) {
                    out.println(-1);
                    return;
                }
                r1 = Math.max(r1, e[0]);
                r2 = Math.min(r2, e[1]);
            }
            if (r1 >= r2) {
                out.println(-1);
            } else {
                out.printf("%.15f\n", r1);
            }
        }

        public double[] get(int s, int v, int a1, int a2) {
            if (v == 0) {
                if (s > a1 && s < a2) {
                    return new double[]{0, 1L << 60};
                } else {
                    return new double[]{-1, -1};
                }
            }
            double lo = -1;
            if (s < a1) {
                lo = (a1 - s) / (double) v;
            }
            double hi = -1;
            if (s < a2) {
                hi = (a2 - s) / (double) v;
            }
            return new double[]{lo, hi};
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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}