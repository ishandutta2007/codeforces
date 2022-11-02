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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int t = in.nextInt();
                for (int test = 0; test < t; test++) {
                        int n = in.nextInt();
                        int p = in.nextInt();
                        boolean[][] edge = new boolean[n][n];
                        for (int i = 0; i < n; i++)
                                edge[i][(i + 1) % n] = edge[(i + 1) % n][i] = true;
                        for (int i = 0; i < n; i++)
                                edge[i][(i + 2) % n] = edge[(i + 2) % n][i] = true;
                        for (int i = 0; i < n; i++)
                                for (int j = 0; j < n; j++) {
                                        if (i == j || p == 0 || edge[i][j])
                                                continue;
                                        edge[i][j] = edge[j][i] = true;
                                        p--;
                                }
                        for (int i = 0; i < n; i++)
                                for (int j = i + 1; j < n; j++)
                                        if (edge[i][j])
                                                out.println((i + 1) + " " + (j + 1));
                }
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