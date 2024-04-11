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
        HBreadboardCapacity solver = new HBreadboardCapacity();
        solver.solve(1, in, out);
        out.close();
    }

    static class HBreadboardCapacity {
        int n;
        int m;
        String col = "RB";
        String dir = "LRUD";

        int get(int[][] grid) {
            int x = 0;
            int ans = Integer.MAX_VALUE;
            for (int kk = 0; kk < 2; kk++) {
                int[][] dp = new int[n + 1][2];
                for (int j = 0; j < m; j++) {
                    dp[0][grid[2 ^ x][j]]++;
                }
                for (int i = 0; i < n; i++) {
                    int c = grid[0 ^ x][i] + grid[1 ^ x][i];
                    dp[i + 1][0] = Math.min(dp[i][0] + 2 - c, dp[i][1] + m + c);
                    dp[i + 1][1] = Math.min(dp[i][1] + c, dp[i][0] + m + 2 - c);
                }
                for (int j = 0; j < m; j++) {
                    dp[n][grid[3 ^ x][j]]++;
                }
                ans = Math.min(ans, dp[n][0]);
                ans = Math.min(ans, dp[n][1]);
                int t = n;
                n = m;
                m = t;
                x ^= 2;
            }
            return ans;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            int q = in.nextInt();
            int[][] g = new int[4][];
            for (int i = 0; i < 4; i++) {
                char[] x = in.next().toCharArray();
                g[i] = new int[x.length];
                for (int k = 0; k < x.length; k++) {
                    g[i][k] = col.indexOf(x[k]);
                }
            }
            out.println(get(g));
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

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
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

        public void println(int i) {
            writer.println(i);
        }

    }
}