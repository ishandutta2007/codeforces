import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public long[] fact;
        public long[] invfact;
        public int mod = 1000000007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            char[] s = in.next().toCharArray();
            ArrayList<Character> arr = new ArrayList<>();
            for (int i = 0; i < s.length; i++) {
                if (i == 0 || (s[i] != s[i - 1])) {
                    arr.add(s[i]);
                }
            }
            char[] k = new char[arr.size()];
            for (int i = 0; i < arr.size(); i++) {
                k[i] = arr.get(i);
            }

            String dd = new String(k);
            int w = dd.length();
            int[][] last = new int[w + 1][26];
            Arrays.fill(last[0], -1);
            for (int i = 1; i <= w; i++) {
                last[i] = Arrays.copyOf(last[i - 1], 26);
                last[i][dd.charAt(i - 1) - 'a'] = i;
            }
            long[][] dp = new long[w + 1][w + 1];
            // [i][j] -> number of distinct subsequences of [1..i] of length j
            for (int i = 0; i <= w; i++) dp[i][0] = 1;
            for (int length = 1; length <= w; length++) {
                for (int i = 1; i <= w; i++) {
                    dp[i][length] = (dp[i - 1][length] + dp[i - 1][length - 1]);
                    if (dp[i][length] >= mod) dp[i][length] -= mod;
                    int q = last[i - 1][dd.charAt(i - 1) - 'a'];
                    if (q != -1) {
                        dp[i][length] += (mod - dp[q][length - 1]);
                        if (dp[i][length] >= mod) dp[i][length] -= mod;
                    }
                }
            }
            long[][] x = Factorials.getFIF(10000, mod);
            fact = x[0];
            invfact = x[1];
            long ret = 0;
            for (int length = 1; length <= dd.length(); length++) {
                ret = (ret + dp[w][length] * comb(n - 1, length - 1)) % mod;
            }
            out.println(ret);
        }

        public long comb(int n, int k) {
            if (k < 0 || k > n) return 0;
            return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
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