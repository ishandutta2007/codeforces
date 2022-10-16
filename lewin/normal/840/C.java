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
        public int mod = 1000000007;
        public int MAXN = 333;
        public int[][] w1;
        public long[] fact;
        public long[] ifact;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long[][] e = Factorials.getFIF(MAXN, mod);
            fact = e[0];
            ifact = e[1];
            w1 = new int[MAXN][MAXN];
            w1[0][0] = 1;
            for (int i = 1; i < MAXN; i++) {
                for (int j = 1; j < MAXN; j++) {
                    for (int k = 1; k <= i; k++) {
                        w1[i][j] += w1[i - k][j - 1];
                        if (w1[i][j] >= mod) w1[i][j] -= mod;
                    }
                }
            }

            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            boolean[] marked = new boolean[n];
            int[] fs = new int[n];
            int fidx = 0;
            for (int i = 0; i < n; i++) {
                if (marked[i]) continue;
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (isSquare(1L * arr[i] * arr[j])) {
                        if (marked[j]) System.exit(1);
                        marked[j] = true;
                        count++;
                    }
                }
                fs[fidx++] = count;
            }

            fs = Arrays.copyOf(fs, fidx);
            long x = 1;
            for (int j : fs) x = x * fact[j] % mod;
            x = x * solve(fs) % mod;
            out.println(x);
        }

        public boolean isSquare(long x) {
            long d = (long) (Math.sqrt(x));
            while (d * d < x) d++;
            while (d * d > x) d--;
            return d * d == x;
        }

        public int solve(int[] freq) {
            int d = AUtils.sum(freq);
            int b = AUtils.max(freq);
            if (d == 0) return 1;
            if (b + b - 1 > d) return 0;
            int[] dp = new int[1];
            dp[0] = 1;
            for (int j = 0; j < freq.length; j++) {
                if (freq[j] == 0) continue;
                int[] nxt = new int[dp.length + freq[j]];
                for (int pgr = 0; pgr < dp.length; pgr++) {
                    for (int cgr = 1; cgr <= freq[j]; cgr++) {
                        nxt[pgr + cgr] += 1L * dp[pgr] * w1[freq[j]][cgr] % mod * ifact[cgr] % mod;
                        if (nxt[pgr + cgr] >= mod) nxt[pgr + cgr] -= mod;
                    }
                }
                dp = nxt;
            }

            int res = 0;
            for (int i = 0; i < dp.length; i++) {
                long x = 1L * dp[i] * fact[i] % mod;
                if ((d - i) % 2 == 0) res += x;
                else res -= x;
                if (res >= mod) res -= mod;
                if (res < 0) res += mod;
            }
            return res;
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

    static class AUtils {
        public static int max(int[] arr) {
            int res = arr[0];
            for (int x : arr) res = Math.max(res, x);
            return res;
        }

        public static int sum(int[] arr) {
            int sum = 0;
            for (int x : arr) {
                sum += x;
            }
            return sum;
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

    }
}