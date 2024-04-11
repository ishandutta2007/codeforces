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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int mod = in.nextInt();
        int[][][][] dp = new int[n + 1][k][2][2];
        dp[0][0][0][0] = 1 % mod;
        int[] pw = new int[n];
        pw[0] = 1 % k;
        for (int i = 1; i < n; i++)
            pw[i] = pw[i - 1] * 10 % k;
        for (int len = 0; len < n; len++)
            for (int prevMod = 0; prevMod < k; prevMod++)
                for (int wasY = 0; wasY < 2; wasY++)
                    for (int wasNonZero = 0; wasNonZero < 2; wasNonZero++)
                        for (int d = (len == n - 1) ? 1 : 0; d <= 9; d++) {
                            int curMod = (prevMod + pw[len] * d) % k;
                            int curWasY = wasY;
                            int curWasNonZero = wasNonZero;
                            if (d > 0)
                                curWasNonZero = 1;
                            if (curWasNonZero == 1 && curMod == 0)
                                curWasY = 1;
                            dp[len + 1][curMod][curWasY][curWasNonZero] += dp[len][prevMod][wasY][wasNonZero];
                            dp[len + 1][curMod][curWasY][curWasNonZero] %= mod;
                        }
        int res = 0;
        for (int curMod = 0; curMod < k; curMod++)
            res = (res + dp[n][curMod][1][1]) % mod;
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