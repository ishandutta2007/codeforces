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
    int[] a;
    int[] sum;
    int[] dp;

    void dfs(int v) {
        if (2 * v >= a.length) {
            sum[v] = a[v];
            dp[v] = 0;
            return;
        }
        dfs(2 * v);
        dfs(2 * v + 1);
        sum[v] = Math.max(sum[2 * v], sum[2 * v + 1]) + a[v];
        dp[v] = dp[2 * v] + dp[2 * v + 1] + Math.abs(sum[2 * v] - sum[2 * v + 1]);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        a = new int[22222];
        dp = new int[22222];
        sum = new int[22222];
        for (int i = 2; i < 2 + ((1 << (n + 1)) - 2); i++)
            a[i] = in.nextInt();
        dfs(1);
        out.println(dp[1]);
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