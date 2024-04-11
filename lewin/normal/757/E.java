import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public int mod = 1000000007;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int q = in.nextInt();
            long[][] dp = new long[20][1000010];
            for (int i = 0; i < dp.length; i++) dp[i][1] = 1;
            for (int pos = 2; pos < dp[0].length; pos++) {
                for (int val = 0; val < dp.length; val++) {
                    long ret = dp[val][pos - 1];
                    if (val > 0) {
                        ret += dp[val - 1][pos];
                        if (ret >= mod) ret -= mod;
                    }
                    dp[val][pos] = ret;
                }
            }
            int[] nextprime = new int[1000001];
            for (int i = 2; i < nextprime.length; i++) {
                if (nextprime[i] == 0) {
                    for (int j = i; j < nextprime.length; j += i) {
                        nextprime[j] = i;
                    }
                }
            }
            while (q-- > 0) {
                int r = in.nextInt(), n = in.nextInt();
                long ret = 1;
                while (n > 1) {
                    int d = nextprime[n];
                    int c = 0;
                    while (n % d == 0) {
                        n /= d;
                        c++;
                    }
                    ret = ret * (dp[c - 1][r + 1] * 2 + dp[c][r]) % mod;
                }
                out.println(ret);
            }
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