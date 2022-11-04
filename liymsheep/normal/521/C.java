import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private static final int MODULO = 1000000007;

        private long powMod(long x, int y) {
            long z = 1L;
            for (; y != 0; y >>= 1) {
                if (y % 2 == 1) {
                    z = z * x % MODULO;
                }
                x = x * x % MODULO;
            }
            return z;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            long[] fac = new long[n + 1];
            long[] dfac = new long[n + 1];
            fac[0] = dfac[0] = 1L;
            for (int i = 1; i <= n; ++i) {
                fac[i] = fac[i - 1] * i % MODULO;
                dfac[i] = dfac[i - 1] * powMod(i, MODULO - 2) % MODULO;
            }

            char[] s = in.next().toCharArray();
            long answer = 0L;
            if (k == 0) {
                for (int i = 0; i < s.length; ++i) {
                    answer = (answer * 10 + s[i] - '0') % MODULO;
                }
                out.println(answer);
                return;
            }

            long coef = 0;
            int slots = n - 1;
            for (int i = 0; i < n - 1; ++i) {
                if (k >= 1 && slots - i >= k) {
                    coef += powMod(10, i) * fac[slots - i - 1] % MODULO
                            * dfac[k - 1] % MODULO * dfac[slots - i - k] % MODULO;
                }
            }
            coef %= MODULO;

            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    coef += powMod(10, n - 1 - i) * fac[i] % MODULO
                            * dfac[k] % MODULO * dfac[i - k] % MODULO;
                    coef %= MODULO;
                }

                answer = (answer + coef * (s[i] - '0')) % MODULO;
                if (n - 2 - i >= 0 && k >= 1 && slots - (n - 2 - i) >= k) {
                    coef -= powMod(10, n - 2 - i) * fac[slots - (n - 2 - i) - 1] % MODULO
                            * dfac[k - 1] % MODULO * dfac[slots - (n - 2 - i) - k] % MODULO;
                }

                if (i >= k) {
                    coef -= powMod(10, n - 1 - i) * fac[i] % MODULO
                            * dfac[k] % MODULO * dfac[i - k] % MODULO;
                    coef %= MODULO;
                }
            }

            if (answer < 0) {
                answer += MODULO;
            }

            out.println(answer);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}