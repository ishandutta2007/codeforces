import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    final int INF = 1_000_000_000;
    final int N = 30_000 + 10;
    final int A = 300;
    final int B = 500;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int d = in.nextInt();
        int[] cnt = new int[N];
        for (int i = 0; i < n; i++) {
            int p = in.nextInt();
            cnt[p]++;
        }
        int[][] dp = new int[N][B];
        for (int i = 0; i < N; i++)
            Arrays.fill(dp[i], -INF);
        if (d <= A) {
            dp[d][d] = cnt[d];
            for (int pos = d; pos < N; pos++)
                for (int len = 1; len < B; len++) {
                    if (pos + len < N) {
                        dp[pos + len][len] = Math.max(dp[pos + len][len], dp[pos][len] + cnt[pos + len]);
                    }
                    if (pos + len + 1 < N && len + 1 < B) {
                        dp[pos + len + 1][len + 1] = Math.max(dp[pos + len + 1][len + 1],
                                dp[pos][len] + cnt[pos + len + 1]);
                    }
                    if (pos + len - 1 < N && len - 1 > 0) {
                        dp[pos + len - 1][len - 1] = Math.max(dp[pos + len - 1][len - 1],
                                dp[pos][len] + cnt[pos + len - 1]);
                    }
                }
        } else {
            int offset = d - B / 2;
            dp[d][d - offset] = cnt[d];
            for (int pos = d; pos < N; pos++)
                for (int len = 1; len < B; len++) {
                    if (pos + len + offset < N) {
                        dp[pos + len + offset][len] = Math.max(dp[pos + len + offset][len],
                                dp[pos][len] + cnt[pos + len + offset]);
                    }
                    if (pos + len + 1 + offset < N && len + 1 < B) {
                        dp[pos + len + 1 + offset][len + 1] = Math.max(dp[pos + len + 1 + offset][len + 1],
                                dp[pos][len] + cnt[pos + len + 1 + offset]);
                    }
                    if (pos + len - 1 + offset < N && len - 1 > 0) {
                        dp[pos + len - 1 + offset][len - 1] = Math.max(dp[pos + len - 1 + offset][len - 1],
                                dp[pos][len] + cnt[pos + len - 1 + offset]);
                    }
                }
        }
        int res = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < B; j++)
                res = Math.max(res, dp[i][j]);
        out.println(res);
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                // ignore
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}