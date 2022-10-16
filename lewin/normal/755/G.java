import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public int deg;
        public int mod = 998244353;
        public int d;
        public int[] swap;
        public int[] omega;
        public HashMap<Integer, int[]> mp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            deg = Math.max(1 << 3, Integer.highestOneBit(k) << 1);
            swap = new int[deg << 1];
            long om = Utils.mod_exp(3, (mod - 1) / (deg << 1), mod);
            omega = new int[deg << 1];
            omega[0] = 1;
            for (int i = 1; i < deg << 1; i++) {
                omega[i] = (int) ((1L * omega[i - 1] * om) % mod);
            }

            int shift = 32 - Integer.numberOfTrailingZeros(deg << 1);
            for (int i = 1; i < deg << 1; i++) {
                swap[i] = Integer.reverse(i << shift);
            }
            d = (int) inv(deg << 1, mod);
            mp = new HashMap<>();
            int[] x = solve(n);
            fft(x, true);
            for (int i = 1; i <= k; i++) {
                if (i != 1) out.print(" ");
                out.print(x[i]);
            }
            out.println();
        }

        public int[] solve(int n) {
            if (mp.containsKey(n)) return mp.get(n);
            if (n <= 500) {
                int[][] dp = new int[3][deg << 1];
                dp[0][0] = 1;
                for (int i = 1; i <= n; i++) {
                    int cur = i % 3;
                    int d1 = (i - 1 + 3) % 3;
                    int d2 = (i - 2 + 3) % 3;
                    Arrays.fill(dp[cur], 0);
                    for (int groups = 0; groups < deg; groups++) {
                        if (groups > 0) {
                            dp[cur][groups] += dp[d1][groups - 1];
                            if (dp[cur][groups] >= mod) dp[cur][groups] -= mod;
                            dp[cur][groups] += dp[d2][groups - 1];
                            if (dp[cur][groups] >= mod) dp[cur][groups] -= mod;
                        }
                        dp[cur][groups] += dp[d1][groups];
                        if (dp[cur][groups] >= mod) dp[cur][groups] -= mod;
                    }
                }
                int[] ret = dp[n % 3];
                fft(ret, false);
                mp.put(n, ret);
                return ret;
            }
            int h1 = n / 2;
            int h2 = n - h1;
            int[] a1 = solve(h1).clone();
            int[] a2 = solve(h2).clone();
            int[] a3 = solve(h1 - 1).clone();
            int[] a4 = solve(h2 - 1).clone();
            for (int i = 0; i < deg << 1; i++) {
                a1[i] = (int) ((long) a1[i] * a2[i] % mod);
                a3[i] = (int) ((long) a3[i] * a4[i] % mod);
            }
            fft(a1, true);
            fft(a3, true);
            int[] ret = new int[deg << 1];
            ret[0] = a1[0];
            for (int i = 1; i < deg; i++) {
                ret[i] = a1[i] + a3[i - 1];
                if (ret[i] >= mod) ret[i] -= mod;
            }
            fft(ret, false);
            mp.put(n, ret);
            return ret;
        }

        public void fft(int[] a, boolean inv) {
            int n = a.length;
            for (int i = 1; i < n; i++) {
                if (i < swap[i]) {
                    int temp = a[i];
                    a[i] = a[swap[i]];
                    a[swap[i]] = temp;
                }
            }
            for (int len = 2; len <= n; len <<= 1) {
                for (int i = 0; i < n; i += len) {
                    int pos = 0;
                    for (int j = 0; j < len / 2; ++j) {
                        int u = a[i + j];
                        int v = (int) ((long) a[i + j + len / 2] * omega[pos] % mod);
                        a[i + j] = u + v;
                        if (a[i + j] >= mod) a[i + j] -= mod;
                        a[i + j + len / 2] = u - v;
                        if (a[i + j + len / 2] < 0) a[i + j + len / 2] += mod;
                        if (inv) {
                            pos -= n / len;
                            if (pos < 0) pos += n;
                        } else {
                            pos += n / len;
                        }
                    }
                }
            }
            if (inv) {
                for (int i = 0; i < a.length; i++) {
                    a[i] = (int) ((long) a[i] * d % mod);
                }
            }
        }

        public long inv(long N, long M) {
            long x = 0, lastx = 1, y = 1, lasty = 0, q, t, a = N, b = M;
            while (b != 0) {
                q = a / b;
                t = a % b;
                a = b;
                b = t;
                t = x;
                x = lastx - q * x;
                lastx = t;
                t = y;
                y = lasty - q * y;
                lasty = t;
            }
            return (lastx + M) % M;
        }

    }

    static class Utils {
        public static long mod_exp(long b, long e, long mod) {
            long res = 1;
            while (e > 0) {
                if ((e & 1) == 1)
                    res = (res * b) % mod;
                b = (b * b) % mod;
                e >>= 1;
            }
            return res;
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}