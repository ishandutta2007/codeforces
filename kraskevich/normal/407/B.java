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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
        final long MOD = 1_000_000_000 + 7;
        long[][] dp;
        int[] p;

        long getDp(int from, int to) {
                if (from == to)
                        return dp[from][to] = 0;
                if (dp[from][to] >= 0)
                        return dp[from][to];
                return dp[from][to] = (getDp(p[from], from) + getDp(from + 1, to) + 2) % MOD;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                p = ArrayUtils.readIntArray(in, n);
                for (int i = 0; i < n; i++)
                        p[i]--;
                dp = new long[n][n];
                for (int i = 0; i < n; i++)
                        Arrays.fill(dp[i], -1);
                long res = getDp(0, n - 1) + getDp(p[n - 1], n - 1) + 2;
                out.println(res % MOD);
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

class ArrayUtils {

        public static int[] readIntArray(FastScanner in, int count) {
                int[] array = new int[count];
                for (int i = 0; i < count; i++)
                        array[i] = in.nextInt();
                return array;
        }


}