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
        ETrainHardWinEasy solver = new ETrainHardWinEasy();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETrainHardWinEasy {
        int n;
        int m;
        ETrainHardWinEasy.Point[] ps;
        long[] ans;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            ps = new ETrainHardWinEasy.Point[n];
            for (int i = 0; i < n; i++) {
                ps[i] = new ETrainHardWinEasy.Point(in.nextInt(), in.nextInt(), i);
            }
            ans = new long[n];
//        for (int i = 0; i < n; i++) {
//            for (int j = i+1; j < n; j++) {
//                long t = Math.min(ps[i].x+ps[j].y, ps[i].y+ps[j].x);
//                ans[i] += t;
//                ans[j] += t;
//            }
//        }
//        Debug.print(ans);
            for (int i = 0; i < n; i++) {
                ans[i] = 1L * (n - 1) * (ps[i].x + ps[i].y);
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                long t = Math.min(ps[a].x + ps[b].y, ps[a].y + ps[b].x);
                ans[a] -= t;
                ans[b] -= t;
            }

            Arrays.sort(ps, Comparator.comparingInt(g -> g.y - g.x));
            long sx = 0;
            for (int i = 0; i < n; i++) sx += ps[i].x;
            long sy = 0;
            for (int i = 0; i < n; i++) {
                sx -= ps[i].x;
                ans[ps[i].id] += sx - 1L * ps[i].x * (n - i - 1) + sy - 1L * ps[i].y * i;
                sy += ps[i].y;
            }
            out.println(ans);
        }

        static class Point {
            public int x;
            public int y;
            public int id;

            public Point(int x, int y, int id) {
                this.x = x;
                this.y = y;
                this.id = id;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 20];
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

        public void print(long[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(long[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}