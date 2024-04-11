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
        final int n = 1000;
        final int maxLen = 80;
        char[][] s = new char[n][n];

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                long k = in.nextLong();
                for (int i = 0; i < n; i++)
                        Arrays.fill(s[i], 'N');
                int v = maxLen + 3;
                for (int i = 2; i <= maxLen + 2; i++)
                        addEdge(i - 1, i);
                addEdge(2, 1);
                addEdge(0, v);
                for (int i = 0; i < 31; i++) {
                        if ((k & (1L << i)) != 0) {
                                int delta = (31 - i) * 2;
                                int id = delta + 1;
                                addEdge(v, id);
                        }
                        addEdge(v, v + 1);
                        addEdge(v, v + 2);
                        addEdge(v + 1, v + 3);
                        addEdge(v + 2, v + 3);
                        v += 3;
                }
                out.println(n);
                for (int i = 0; i < n; i++) {
                        StringBuilder sb = new StringBuilder();
                        for (char c : s[i])
                                sb.append(c);
                        out.println(sb.toString());
                }

        }

        void addEdge(int a, int b) {
                s[a][b] = s[b][a] = 'Y';
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

        public long nextLong() {
                return Long.parseLong(nextToken());
        }

        }