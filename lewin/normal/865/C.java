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
            int n = in.nextInt(), r = in.nextInt();
            int[] f = new int[n], s = new int[n];
            double[] p = new double[n];
            int[] g = new int[n];
            int sum = 0;
            int sf = 0;
            for (int i = 0; i < n; i++) {
                f[i] = in.nextInt();
                s[i] = in.nextInt();
                p[i] = in.nextInt() / 100.0;
                g[i] = s[i] - f[i];
                sum += s[i];
                sf += f[i];
            }
            int needg = (sum - r);
            double lo = sf, hi = 1L << 50;
            for (int iter = 0; iter < 80; iter++) {
                double mid = (lo + hi) / 2.0;
                double[][] dp = new double[n + 1][needg + 1];
                for (int i = 0; i < needg; i++) {
                    dp[n][i] = mid;
                }
                dp[n][needg] = 0;
                for (int i = n - 1; i >= 0; i--) {
                    for (int have = 0; have <= needg; have++) {
                        // restart, try level
                        int nhave = Math.min(needg, have + g[i]);
                        dp[i][have] = Math.min(mid, (dp[i + 1][nhave] + f[i]) * p[i] + (1 - p[i]) * (dp[i + 1][have] + s[i]));
                    }
                }

                if (dp[0][0] < mid) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            out.printf("%.10f\n", (lo + hi) / 2.0);
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