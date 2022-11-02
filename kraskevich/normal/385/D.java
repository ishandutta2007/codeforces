import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
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
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int L = in.nextInt();
                int R = in.nextInt();
                int[] x = new int[n];
                int[] y = new int[n];
                double a[] = new double[n];
                for (int i = 0; i < n; i++) {
                        x[i] = in.nextInt();
                        y[i] = in.nextInt();
                        a[i] = in.nextInt();
                        a[i] /= 180.0;
                        a[i] *= Math.PI;
                }
                double dp[] = new double[1 << n];
                Arrays.fill(dp, L);
                for (int mask = 0; mask < (1 << n); mask++)
                        for (int i = 0; i < n; i++) {
                                if ((mask & (1 << i)) != 0)
                                        continue;
                                double newX = getNewX(x[i], y[i], a[i], dp[mask]);
                                dp[mask | (1 << i)] = Math.max(dp[mask | (1 << i)], newX);
                        }
                out.format("%.9f", Math.min(dp[(1 << n) - 1] - L, (double)R - L));
        }

        double getNewX(int x0, int y0, double angle, double oldX) {
                double dx = oldX - x0;
                double alpha = Math.atan(dx / y0);
                double beta = alpha + angle;
                if (beta > Math.PI / 2.0 - 1e-9)
                        return 1e9;
                return Math.tan(beta) * y0 + x0;
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

        public int nextInt() {
                return Integer.parseInt(nextToken());
        }

        }