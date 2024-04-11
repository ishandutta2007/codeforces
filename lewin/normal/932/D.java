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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[][] par;
        long[][] weights;
        int nidx;
        int last;
        public int LOG = 21;

        void addEdge(int p, int node, int w) {
            for (int i = LOG - 1; i >= 0; i--) {
                if (par[p][i] != -1 && weights[par[p][i]][0] < w) {
                    p = par[p][i];
                }
            }
            if (weights[p][0] < w) p = par[p][0];
            par[node][0] = p;
            weights[node][0] = w;
            int cur = p;
            for (int i = 1; i < LOG; i++) {
                if (cur != -1) {
                    weights[node][i] = weights[node][i - 1] + weights[cur][i - 1];
                    par[node][i] = cur = par[cur][i - 1];
                } else {
                    weights[node][i] = 1L << 60;
                    par[node][i] = -1;
                }
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            nidx = 1;
            last = 0;
            int q = in.nextInt();
            par = new int[q + 1][LOG];
            Arrays.fill(par[0], -1);
            weights = new long[q + 1][LOG];
            Arrays.fill(weights[0], 1L << 60);
            weights[0][0] = 0;
            while (q-- > 0) {
                int type = in.nextInt();
                if (type == 1) {
                    int par = (int) ((in.nextLong() ^ last) - 1);
                    int weight = (int) (in.nextLong() ^ last);
                    addEdge(par, nidx++, weight);
                } else {
                    int node = (int) (in.nextLong() ^ last) - 1;
                    long X = in.nextLong() ^ last;
                    int ans = 0;
                    for (int i = LOG - 1; i >= 0; i--) {
                        if (node != -1 && weights[node][i] <= X) {
                            X -= weights[node][i];
                            ans += 1 << i;
                            node = par[node][i];
                        }
                    }
                    last = ans;
                    out.println(ans);
                }
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
}