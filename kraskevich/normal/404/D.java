import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
        final int MOD = 1_000_000_007;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                char[] s = in.nextToken().toCharArray();
                int n = s.length;
                int[][][] dp = new int[2][2][n + 1];
                dp[0][0][0] = 1;
                for (int pos = 0; pos < n; pos++)
                        for (int bombs = 0; bombs < 2; bombs++)
                                for (int want = 0; want < 2; want++) {
                                        if (bombs == 1) {
                                                //put a bomb
                                                if (s[pos] == '*' || s[pos] == '?') {
                                                        dp[1][0][pos + 1] += dp[bombs][want][pos];
                                                        dp[1][0][pos + 1] %= MOD;
                                                }
                                                //put one
                                                if (s[pos] == '1' || s[pos] == '?') {
                                                        dp[0][0][pos + 1] += dp[bombs][want][pos];
                                                        dp[0][0][pos + 1] %= MOD;
                                                }
                                                //put two
                                                if (s[pos] == '2' || s[pos] == '?') {
                                                        dp[0][1][pos + 1] += dp[bombs][want][pos];
                                                        dp[0][1][pos + 1] %= MOD;
                                                }
                                        } else {
                                                if (want == 0 || pos == 0) {
                                                        //put zero
                                                        if (s[pos] == '0' || s[pos] == '?') {
                                                                dp[0][0][pos + 1] += dp[bombs][want][pos];
                                                                dp[0][0][pos + 1] %= MOD;
                                                        }
                                                        //put one
                                                        if (s[pos] == '1' || s[pos] == '?') {
                                                                dp[0][1][pos + 1] += dp[bombs][want][pos];
                                                                dp[0][1][pos + 1] %= MOD;
                                                        }
                                                }
                                                if (want == 1 || pos == 0) {
                                                        //put a bomb
                                                        if (s[pos] == '*' || s[pos] == '?') {
                                                                dp[1][0][pos + 1] += dp[bombs][want][pos];
                                                                dp[1][0][pos + 1] %= MOD;
                                                        }
                                                }
                                        }
                                }
                int res = dp[1][0][n] + dp[0][0][n];
                res %= MOD;
                out.print(res);
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        }