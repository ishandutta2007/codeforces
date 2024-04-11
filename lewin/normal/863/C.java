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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long k = in.nextLong();
            int ia = in.nextInt() - 1, ib = in.nextInt() - 1;
            int[][] nexta = new int[3][3];
            int[][] nextb = new int[3][3];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    nexta[i][j] = in.nextInt() - 1;
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    nextb[i][j] = in.nextInt() - 1;
                }
            }

            int[][] score = new int[][]{
                    {0, 0, 1},
                    {1, 0, 0},
                    {0, 1, 0}
            };

            int[][] iter = new int[3][3];
            for (int[] x : iter) Arrays.fill(x, -1);
            int ca = ia, cb = ib;
            int citer = 0;
            long sa = 0, sb = 0;
            while (citer < k) {
                if (iter[ca][cb] != -1) break;
                iter[ca][cb] = citer++;
                sa += score[ca][cb];
                sb += score[cb][ca];
                int na = nexta[ca][cb];
                int nb = nextb[ca][cb];
                ca = na;
                cb = nb;
            }

            if (citer == k) {
                out.println(sa + " " + sb);
                return;
            }

            k -= citer;
            int oa = ca, ob = cb;
            int lencyc = 0;
            long ta = 0, tb = 0;
            do {
                ta += score[ca][cb];
                tb += score[cb][ca];
                int na = nexta[ca][cb];
                int nb = nextb[ca][cb];
                ca = na;
                cb = nb;
                lencyc++;
            } while (oa != ca || ob != cb);

            sa += ta * (k / lencyc);
            sb += tb * (k / lencyc);
            k %= lencyc;

            while (k-- > 0) {
                sa += score[ca][cb];
                sb += score[cb][ca];
                int na = nexta[ca][cb];
                int nb = nextb[ca][cb];
                ca = na;
                cb = nb;
            }


            out.println(sa + " " + sb);
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
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

    }
}