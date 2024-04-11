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
        int r = in.nextInt();
        int s = in.nextInt();
        int p = in.nextInt();
        double[][][] dp = new double[r + 1][s + 1][p + 1];
        dp[r][s][p] = 1.0;
        for (int i = r; i >= 0; i--)
            for (int j = s; j >= 0; j--)
                for (int k = p; k >= 0; k--) {
                    int tot = i * j + i * k + j * k;
                    if (i > 0 && j > 0)
                        dp[i][j - 1][k] += i * j * dp[i][j][k] / tot;
                    if (i > 0 && k > 0)
                        dp[i - 1][j][k] += i * k * dp[i][j][k] / tot;
                    if (j > 0 && k > 0)
                        dp[i][j][k - 1] += j * k * dp[i][j][k] / tot;
                }
        double s1 = 0;
        for (int i = 1; i <= r; i++)
            s1 += dp[i][0][0];
        double s2 = 0;
        for (int i = 1; i <= s; i++)
            s2 += dp[0][i][0];
        double s3 = 0;
        for (int i = 1; i <= p; i++)
            s3 += dp[0][0][i];
        out.printf("%.10f %.10f %.10f", s1, s2, s3);
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