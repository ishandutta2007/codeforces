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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BLynyrdSkynyrd solver = new BLynyrdSkynyrd();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLynyrdSkynyrd {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
            int[] p = in.readIntArrayAndDecrementOne(n);
            int[] arr = in.readIntArrayAndDecrementOne(m);
            int[] prev = new int[n];
            prev[p[0]] = p[n - 1];
            for (int i = 1; i < n; i++) {
                prev[p[i]] = p[i - 1];
            }
            int[][] ap = new int[20][m];
            int[] last = new int[n];
            Arrays.fill(last, -1);
            for (int i = 0; i < m; i++) {
                ap[0][i] = last[prev[arr[i]]];
                last[arr[i]] = i;
            }
            for (int level = 1; level < ap.length; level++) {
                for (int j = 0; j < m; j++) {
                    ap[level][j] = ap[level - 1][j] == -1 ? -1 : ap[level - 1][ap[level - 1][j]];
                }
            }

            int[] pn = new int[m];
            for (int i = 0; i < m; i++) {
                pn[i] = i;
                for (int k = 0; k < ap.length; k++) {
                    if ((((n - 1) >> k) & 1) == 1 && pn[i] != -1) {
                        pn[i] = ap[k][pn[i]];
                    }
                }
                pn[i] = -pn[i];
            }
            RmqSparseTable rmq = new RmqSparseTable(pn);

            char[] ret = new char[q];
            for (int i = 0; i < q; i++) {
                int l = in.nextInt() - 1, r = in.nextInt() - 1;
                ret[i] = -rmq.min(l, r) >= l ? '1' : '0';
            }
            out.println(new String(ret));
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

    static class RmqSparseTable {
        int[] logTable;
        int[][] rmq;
        int[] a;

        public RmqSparseTable(int[] a) {
            this.a = a;
            int n = a.length;

            logTable = new int[n + 1];
            for (int i = 2; i <= n; i++)
                logTable[i] = logTable[i >> 1] + 1;

            rmq = new int[logTable[n] + 1][n];

            for (int i = 0; i < n; ++i)
                rmq[0][i] = i;

            for (int k = 1; (1 << k) < n; ++k) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    int x = rmq[k - 1][i];
                    int y = rmq[k - 1][i + (1 << k - 1)];
                    rmq[k][i] = a[x] <= a[y] ? x : y;
                }
            }
        }

        public int min(int i, int j) {
            int k = logTable[j - i];
            int x = rmq[k][i];
            int y = rmq[k][j - (1 << k) + 1];
            return Math.min(a[x], a[y]);
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

        public int[] readIntArrayAndDecrementOne(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt() - 1;
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
}