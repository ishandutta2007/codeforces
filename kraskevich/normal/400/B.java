import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
        final int N = 2222;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int m = in.nextInt();
                char[][] field = new char[n][];
                for (int i = 0; i < n; i++) {
                        String s = in.nextToken();
                        field[i] = s.toCharArray();
                }
                boolean[] was = new boolean[N];
                for (int i = 0; i < n; i++) {
                        int l = 0;
                        int r = 0;
                        while (l < m) {
                                while (l < m && field[i][l] != 'G')
                                        l++;
                                if (l == m)
                                        break;
                                r = l + 1;
                                while (r < m && field[i][r] != 'S')
                                        r++;
                                if (r == m) {
                                        out.print(-1);
                                        return;
                                }
                                was[r - l] = true;
                                l++;
                        }
                }
                int res = 0;
                for (int i = 0; i < N; i++)
                        if (was[i])
                                res++;
                out.print(res);
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