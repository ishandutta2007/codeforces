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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
        final static int N = 10_000_000 + 10;
        boolean[] pr = new boolean[N];
        long[] sum = new long[N];
        long[] count = new long[N];

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                for (int i = 0; i < n; i++) {
                        int curr = in.nextInt();
                        count[curr]++;
                }
                Arrays.fill(pr, true);
                for (int i = 2; i * i < N; i++)
                        if (pr[i])
                                for (int j = i * i; j < N; j += i)
                                        pr[j] = false;
                for (int i = 2; i < N; i++)
                        if (pr[i])
                                for (int j = i; j < N; j += i)
                                        sum[i] += count[j];
                for (int i = 1; i < N; i++)
                        sum[i] += sum[i - 1];
                int m = in.nextInt();
                for (int i = 0; i < m; i++) {
                        int l = in.nextInt();
                        int r = in.nextInt();
                        out.println(get(l, r));
                }
        }

        long get(int l, int r) {
                if (l >= N)
                        return 0;
                return sum[Math.min(r, N - 1)] - sum[l - 1];
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