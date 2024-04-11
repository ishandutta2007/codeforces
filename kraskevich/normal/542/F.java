import java.util.Arrays;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    final int INF = 1_000_000_000;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int T = in.nextInt();
        List<Integer>[] at = new ArrayList[T + 1];
        for (int i = 0; i <= T; i++)
            at[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int t = in.nextInt();
            int q = in.nextInt();
            at[T - t].add(q);
        }
        for (int i = 0; i < at.length; i++) {
            Collections.sort(at[i]);
            Collections.reverse(at[i]);
        }
        int res = 0;
        int[][] dp = new int[T + 1][n + 1];
        for (int i = 0; i < dp.length; i++)
            Arrays.fill(dp[i], -INF);
        dp[0][1] = 0;
        for (int curH = 0; curH < T; curH++) {
            for (int size = 0; size <= n; size++) {
                int add = 0;
                for (int take = 1; take <= Math.min(at[curH].size(), size); take++) {
                    add += at[curH].get(take - 1);
                    dp[curH][size - take] = Math.max(dp[curH][size - take], dp[curH][size] + add);
                }
            }
            for (int size = 0; size <= n; size++)
                dp[curH + 1][Math.min(n, 2 * size)] = Math.max(dp[curH + 1][Math.min(n, 2 * size)], dp[curH][size]);
        }
        for (int i = 0; i < dp.length; i++)
            for (int j = 0; j < dp[i].length; j++)
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