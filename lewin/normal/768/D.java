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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public static double EPS = 1e-7;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int k = in.nextInt(), q = in.nextInt();
            TaskD.Query[] qs = new TaskD.Query[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new TaskD.Query(in.nextInt(), i);
            }
            Arrays.sort(qs, Comparator.comparingInt(a -> a.p));
            double[] dp = new double[k + 1];
            double[] next = new double[k + 1];
            dp[0] = 1;
            int days = 0;
            int[] ans = new int[q];
            for (int i = 0; i < q; i++) {
                int cp = qs[i].p;
                while (cp - EPS > 2000 * dp[k]) {
                    days++;
                    Arrays.fill(next, 0);
                    for (int have = 0; have <= k; have++) {
                        double same = have / (double) k;
                        double diff = 1 - same;
                        if (have + 1 <= k) next[have + 1] += diff * dp[have];
                        next[have] += same * dp[have];
                    }
                    System.arraycopy(next, 0, dp, 0, k + 1);
                }
                ans[qs[i].idx] = days;
            }

            for (int i = 0; i < q; i++) {
                out.println(ans[i]);
            }
        }

        static class Query {
            public int p;
            public int idx;

            public Query(int p, int idx) {
                this.p = p;
                this.idx = idx;
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