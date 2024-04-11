import java.util.ArrayList;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    final long INF = (long)1e11;

    ArrayList<Integer>[] g;
    long[] a;
    long[][] f;
    long res = 0;

    void dfs(int v) {
        long[][] dp = new long[g[v].size() + 1][2];
        for (int i = 0; i < dp.length; i++)
            dp[i][0] = dp[i][1] = -INF;
        dp[0][0] = 0;
        for (int i = 0; i < g[v].size(); i++) {
            int to  = g[v].get(i);
            dfs(to);
            for (int cur = 0; cur < 2; cur++)
                for (int now = 0; now < 2; now++) {
                    int p = (cur + now) % 2;
                    dp[i + 1][p] = Math.max(dp[i + 1][p], dp[i][cur] + f[to][now]);
                }
        }
        f[v][0] = dp[g[v].size()][0];
        f[v][1] = Math.max(dp[g[v].size()][1], f[v][0] + a[v]);
        res = Math.max(res, Math.max(f[v][1], f[v][0]));
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        a = new long[n];
        f = new long[n][2];
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int p = in.nextInt();
            a[i] = in.nextInt();
            p--;
            if (i != 0)
                g[p].add(i);
        }
        dfs(0);
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