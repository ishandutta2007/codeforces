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
        public int x;
        public int k;
        public int n;
        public int q;
        public int[] c;
        public int[] idxtostate;
        public int[] statetoidx;
        public long INF = 1L << 61;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            x = in.nextInt();
            k = in.nextInt();
            n = in.nextInt();
            q = in.nextInt();
            c = in.readIntArray(k);
            TaskC.Stone[] ss = new TaskC.Stone[q + 1];
            for (int i = 0; i < q; i++) ss[i] = new TaskC.Stone(in.nextInt() - 1, in.nextInt());
            ss[q] = new TaskC.Stone(n, 0);
            Arrays.sort(ss, Comparator.comparingInt(ww -> ww.p));
            statetoidx = new int[1 << k];
            idxtostate = new int[1 << k];
            int id = 0;
            for (int i = 0; i < 1 << k; i++) {
                if (Integer.bitCount(i) == x) {
                    statetoidx[i] = id;
                    idxtostate[id] = i;
                    id++;
                }
            }
            long[][][] basepow = new long[60][id][id];
            AUtils.deepFill(basepow, INF);
            for (int i = 0; i < id; i++) {
                int state = idxtostate[i];
                if (((state >> (k - 1)) & 1) == 0) {
                    basepow[0][statetoidx[state]][statetoidx[state << 1]] = 0;
                    continue;
                }
                for (int jump = 1; jump <= k; jump++) {
                    int nstate = state - (1 << (k - 1));
                    nstate <<= 1;
                    if (((nstate >> (k - jump)) & 1) == 1) continue;
                    basepow[0][statetoidx[state]][statetoidx[nstate | (1 << (k - jump))]] = c[jump - 1];
                }
            }
            for (int level = 1; level < basepow.length; level++) {
                basepow[level] = mult(basepow[level - 1], basepow[level - 1]);
            }

            long[][] cost = new long[id][id];
            AUtils.deepFill(cost, INF);
            int ttt = (1 << k) - (1 << (k - x));
            cost[statetoidx[ttt]][statetoidx[ttt]] = 0;

            int cpos = 0;
            int sidx = 0;
            while (cpos < n - x) {
                while (cpos > ss[sidx].p) sidx++;
                if (cpos + k >= ss[sidx].p) {
                    long[][] base = new long[id][id];
                    AUtils.deepFill(base, INF);
                    for (int i = 0; i < id; i++) {
                        int state = idxtostate[i];
                        if (((state >> (k - 1)) & 1) == 0) {
                            base[statetoidx[state]][statetoidx[state << 1]] = 0;
                            continue;
                        }
                        for (int jump = 1; jump <= k; jump++) {
                            int nstate = state - (1 << (k - 1));
                            nstate <<= 1;
                            if (((nstate >> (k - jump)) & 1) == 1) continue;
                            int tcost = c[jump - 1];
                            for (int a = 0; a < 2*k; a++) {
                                if (sidx + a < ss.length && cpos + jump == ss[sidx + a].p) {
                                    tcost += ss[sidx + a].w;
                                }
                            }
                            base[statetoidx[state]][statetoidx[nstate | (1 << (k - jump))]] = tcost;
                        }
                    }
                    cost = mult(cost, base);
                    cpos++;
                } else {
                    long need = (ss[sidx].p - k - cpos);
                    for (int j = 0; j < 60; j++) {
                        if (((need >> j) & 1) == 1) {
                            cost = mult(cost, basepow[j]);
                        }
                    }
                    cpos += need;
                }
            }

            out.println(cost[statetoidx[ttt]][statetoidx[ttt]]);
        }

        public long[][] mult(long[][] a, long[][] b) {
            int n = a.length;
            long[][] ret = new long[n][n];
            AUtils.deepFill(ret, INF);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        ret[i][j] = Math.min(ret[i][j], a[i][k] + b[k][j]);
                    }
                }
            }
            return ret;
        }

        static class Stone {
            public int p;
            public int w;

            public Stone(int p, int w) {
                this.p = p;
                this.w = w;
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }

    static class AUtils {
        public static void deepFill(long[][][] x, long val) {
            for (long[][] y : x) deepFill(y, val);
        }

        public static void deepFill(long[][] x, long val) {
            for (long[] y : x) deepFill(y, val);
        }

        public static void deepFill(long[] x, long val) {
            Arrays.fill(x, val);
        }

    }
}