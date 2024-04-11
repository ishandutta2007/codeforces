import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.io.InputStreamReader;

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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    boolean[][] dp;
    boolean[][] was;
    int n;
    int[] low;
    int[] high;
    PrintWriter out;

    boolean calcDp(int id, int len) {
        if (len == 0)
            return true;
        if (was[id][len])
            return dp[id][len];
        was[id][len] = true;
        for (int pos = 1; pos < len; pos += 2) {
            if (pos < low[id] || pos > high[id])
                continue;
            int d1 = pos - 1;
            int d2 = len - pos - 1;
            boolean left = calcDp(id + 1, d1);
            boolean right = calcDp(id + d1 / 2 + 1, d2);
            if (left && right) {
                dp[id][len] = true;
                break;
            }
        }
        return dp[id][len];
    }

    void reconstruct(int id, int len) {
        if (len == 0)
            return;
        out.print("(");
        for (int pos = 1; pos < len; pos += 2) {
            if (pos < low[id] || pos > high[id])
                continue;
            int d1 = pos - 1;
            int d2 = len - pos - 1;
            boolean left = calcDp(id + 1, d1);
            boolean right = calcDp(id + d1 / 2 + 1, d2);
            if (left && right) {
                reconstruct(id + 1, d1);
                out.print(")");
                reconstruct(id + d1 / 2 + 1, d2);
                break;
            }
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        this.out = out;
        n = in.nextInt();
        low = new int[n];
        high = new int[n];
        for (int i = 0; i < n; i++) {
            low[i] = in.nextInt();
            high[i] = in.nextInt();
        }
        dp = new boolean[n][2 * n + 1];
        was = new boolean[n][2 * n + 1];
        if (!calcDp(0, 2 * n)) {
            out.println("IMPOSSIBLE");
            return;
        }
        reconstruct(0, 2 * n);
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