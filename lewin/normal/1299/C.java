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
        CWaterBalance solver = new CWaterBalance();
        solver.solve(1, in, out);
        out.close();
    }

    static class CWaterBalance {
        long ccw(CWaterBalance.Point a, CWaterBalance.Point b, CWaterBalance.Point c) {
            long dx1 = b.x - a.x;
            long dy1 = b.y - a.y;
            long dx2 = c.x - a.x;
            long dy2 = c.y - a.y;
            return dx1 * dy2 - dy1 * dx2;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            long[] h = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                h[i] = h[i - 1] + arr[i - 1];
            }

            CWaterBalance.Point[] v = new CWaterBalance.Point[n + 1];
            int sidx = 0;
            for (int i = 0; i <= n; i++) {
                CWaterBalance.Point add = new CWaterBalance.Point(i, h[i]);
                while (sidx >= 2 && ccw(v[sidx - 2], v[sidx - 1], add) <= 0) sidx--;
                v[sidx++] = add;
            }
            for (int i = 1; i < sidx; i++) {
                double pr = 1.0 * (v[i].y - v[i - 1].y) / (v[i].x - v[i - 1].x);
                for (int j = (int) v[i - 1].x; j < v[i].x; j++) {
                    out.printf("%.10f\n", pr);
                }
            }
        }

        static class Point {
            public long x;
            public long y;

            public Point(long x, long y) {
                this.x = x;
                this.y = y;
            }

            public String toString() {
                return "Point{" +
                        "x=" + x +
                        ", y=" + y +
                        '}';
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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }
}