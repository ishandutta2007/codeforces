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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public int mod = 1000000007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), D = in.nextInt();
            int[] par = new int[n];
            par[0] = -1;
            for (int i = 1; i < n; i++) {
                par[i] = in.nextInt() - 1;
            }
            int[][] dp = new int[n][n];
            AUtils.deepFill(dp, 1);
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] += dp[i][j - 1];
                    if (dp[i][j] >= mod) dp[i][j] -= mod;
                }
                if (i != 0) {
                    for (int j = 0; j < n; j++) {
                        dp[par[i]][j] = (int) ((1L * dp[par[i]][j] * dp[i][j]) % mod);
                    }
                }
            }
            if (D <= n) {
                out.println(dp[0][D - 1]);
            } else {
                long[][] x = Factorials.getFIF(n + 1010, mod);
                long[] inv = x[2];
                int[][] ccomb = Utils.getComb(n + 10, mod);
                long comb = 1;
                long DK = D;
                long ret = 0;
                long[] f = new long[n];
                for (int j = 0; j < n; j++) {
                    comb = comb * DK % mod;
                    comb = comb * inv[j + 1] % mod;
                    DK--;
                    long nways = dp[0][j];
                    for (int s = 0; s < j; s++) {
                        nways -= f[s] * ccomb[j + 1][s + 1] % mod;
                        if (nways < 0) nways += mod;
                    }
                    f[j] = nways;

                    ret = (ret + f[j] * comb) % mod;
                }
                out.println(ret);
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

    static class Factorials {
        public static long[][] getFIF(int max, int mod) {
            long[] fact = new long[max];
            long[] ifact = new long[max];
            long[] inv = new long[max];
            inv[1] = 1;
            for (int i = 2; i < max; i++) {
                inv[i] = (mod - mod / i) * inv[mod % i] % mod;
            }
            fact[0] = 1;
            ifact[0] = 1;
            for (int i = 1; i < max; i++) {
                fact[i] = fact[i - 1] * i % mod;
                ifact[i] = ifact[i - 1] * inv[i] % mod;
            }
            return new long[][]{fact, ifact, inv};
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

        public void println(int i) {
            writer.println(i);
        }

    }

    static class AUtils {
        public static void deepFill(int[][] x, int val) {
            for (int[] y : x) deepFill(y, val);
        }

        public static void deepFill(int[] x, int val) {
            Arrays.fill(x, val);
        }

    }

    static class Utils {
        public static int[][] getComb(int sz, int mod) {
            int[][] comb = new int[sz][sz];
            for (int i = 0; i < sz; i++) {
                comb[i][0] = 1;
                for (int j = 1; j <= i; j++) {
                    comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
                    if (comb[i][j] >= mod) comb[i][j] -= mod;
                }
            }
            return comb;
        }

    }
}