import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
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
                int n = in.nextInt();
                char[][] s = new char[n][];
                for (int i = 0; i < n; i++)
                        s[i] = in.nextToken().toCharArray();
                char c = s[0][0];
                Set<Character> was = new HashSet<>();
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++) {
                                if (i == j || i + j == n - 1) {
                                        if (c != s[i][j]) {
                                                out.print("NO");
                                                return;
                                        }
                                }  else if (s[i][j] == c) {
                                        out.print("NO");
                                        return;
                                }
                                was.add(s[i][j]);
                        }
                if (was.size() == 2)
                        out.print("YES");
                else
                        out.print("NO");
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