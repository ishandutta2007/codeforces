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
        FGardenerAlex solver = new FGardenerAlex();
        solver.solve(1, in, out);
        out.close();
    }

    static class FGardenerAlex {
        int n;
        int[] arr;
        RmqSparseTable rmq;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            if (n <= 2) {
                out.println(n + " " + 0);
                return;
            }
            arr = in.readIntArrayAndDecrementOne(n);
            rmq = new RmqSparseTable(arr);
            int p1 = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) p1 = i;
            }
            int[] h1 = new int[n];
            {
                int[] stack = new int[n];
                int[] leftdepth = new int[n];
                int[] rightdepth = new int[n];
                int sidx = 0;
                stack[sidx++] = arr[p1];
                leftdepth[0] = 0;
                rightdepth[0] = 0;
                h1[0] = 1;
                int mdepth = 1;
                for (int i = 1; i < n; i++) {
                    int num = arr[(i + p1) % n];
                    while (num < stack[sidx - 1]) {
                        rightdepth[stack[sidx - 2]] = 1 + Math.max(leftdepth[stack[sidx - 1]], rightdepth[stack[sidx - 1]]);
                        mdepth = Math.max(mdepth, sidx - 1 + rightdepth[stack[sidx - 2]]);
                        sidx--;
                    }
                    leftdepth[num] = rightdepth[stack[sidx - 1]];
                    rightdepth[stack[sidx - 1]]++;
                    rightdepth[num] = 0;
                    stack[sidx++] = num;
                    mdepth = Math.max(mdepth, sidx + leftdepth[num]);
                    h1[i] = mdepth;
                }
            }
            int[] h2 = new int[n];
            {
                int[] stack = new int[n];
                int[] leftdepth = new int[n];
                int[] rightdepth = new int[n];
                int sidx = 0;
                stack[sidx++] = arr[p1];
                leftdepth[0] = 0;
                rightdepth[0] = 0;
                h2[0] = 1;
                int mdepth = 1;
                for (int i = 1; i < n; i++) {
                    int num = arr[(p1 - i + n) % n];
                    while (num < stack[sidx - 1]) {
                        rightdepth[stack[sidx - 2]] = 1 + Math.max(leftdepth[stack[sidx - 1]], rightdepth[stack[sidx - 1]]);
                        mdepth = Math.max(mdepth, sidx - 1 + rightdepth[stack[sidx - 2]]);
                        sidx--;
                    }
                    leftdepth[num] = rightdepth[stack[sidx - 1]];
                    rightdepth[stack[sidx - 1]]++;
                    rightdepth[num] = 0;
                    stack[sidx++] = num;
                    mdepth = Math.max(mdepth, sidx + leftdepth[num]);
                    h2[i] = mdepth;
                }
            }

            int min = n, idx = 0;
            for (int i = 0; i < n; i++) {
                int g = Math.max(h2[i], h1[n - i - 1]);
                if (g < min) {
                    min = g;
                    idx = i;
                }
            }
            out.println(min + " " + (p1 - idx + n) % n);
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

    }
}