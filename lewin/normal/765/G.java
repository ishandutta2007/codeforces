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
import java.util.Map;
import java.util.Map.Entry;
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
        public long[] prime;
        public long[] power;
        public int mod = 1000000007;
        public long[] dp;
        public int nzeros;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] c = in.next().toCharArray();
            nzeros = 0;
            for (int i = 0; i < c.length; i++) {
                if (c[i] == '0') {
                    nzeros++;
                }
            }
            int n = in.nextInt();
            long mult = 1;
            prime = new long[n];
            power = new long[n];
            for (int i = 0; i < n; i++) {
                prime[i] = in.nextInt();
                power[i] = in.nextInt();
                mult = mult * Utils.mod_exp(prime[i], power[i] - 1, mod) % mod;
            }
            Arrays.sort(prime);
            int k = 0;
            while (k < n && prime[k] <= c.length) k++;
            dp = new long[nzeros + 1];
            dp[0] = 1;
            for (int i = k; i < n; i++) {
                long[] next = new long[dp.length];
                for (int j = 0; j < dp.length; j++) {
                    // skip all
                    next[j] = (next[j] + (prime[i] - c.length) * dp[j]) % mod;
                    // hit exist
                    next[j] = (next[j] + (nzeros - j) * dp[j]) % mod;
                    // hit new
                    if (j > 0) {
                        next[j] = (next[j] + j * dp[j - 1]) % mod;
                    }
                }
                dp = next;
            }
            HashMap<Long, Integer> dp2 = new HashMap<>();
            dp2.put(0L, 1);
            for (int i = 0; i < k; i++) {
                HashMap<Long, Integer> next = new HashMap<>();
                for (int j = 0; j < prime[i]; j++) {
                    boolean bad = false;
                    long d = 0;
                    for (int w = j; w < c.length; w += prime[i]) {
                        d |= 1L << w;
                        if (c[w] == '1') {
                            bad = true;
                        }
                    }
                    if (!bad) {
                        for (Map.Entry<Long, Integer> e : dp2.entrySet()) {
                            long nk = e.getKey() | d;
                            next.put(nk, (e.getValue() + next.getOrDefault(nk, 0)) % mod);
                        }
                    }
                }
                dp2 = next;
            }
            long nways = 0;
            for (Map.Entry<Long, Integer> e : dp2.entrySet()) {
                nways = (nways + dp[nzeros - Long.bitCount(e.getKey())] * e.getValue()) % mod;
            }
            nways = nways * mult % mod;
            out.println(nways);
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