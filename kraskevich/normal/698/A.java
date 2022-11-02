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
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[][] dp = new int[n + 1][4];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 4; j++)
                dp[i][j] = n;
        dp[0][0] = 0;
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        for (int i = 0; i < n; i++) {
            for (int old = 0; old < 4; old++) {
                for (int newM = 0; newM < 4; newM++) {
                    if ((newM & old) != 0)
                        continue;
                    if ((newM & a[i]) != newM)
                        continue;
                    dp[i + 1][newM] = Math.min(dp[i + 1][newM], dp[i][old] + (newM == 0 ? 1 : 0));
                }
            }
        }
        out.println(Math.min(Math.min(dp[n][0], dp[n][1]), Math.min(dp[n][2], dp[n][3])));
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