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
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int x = in.nextInt();
                boolean[] was = new boolean[x];
                boolean[] div1 = new boolean[x];
                int k = in.nextInt();
                for (int i = 0; i < k; i++) {
                        int t = in.nextInt();
                        if (t == 1) {
                                int a = in.nextInt();
                                int b = in.nextInt();
                                a--;
                                b--;
                                was[a] = was[b] = true;
                                div1[b] = true;
                        } else {
                                int a = in.nextInt();
                                a--;
                                was[a] = true;
                        }
                }
                int max = 0;
                for (int i = 0; i < x - 1; i++)
                        if (!was[i])
                                max++;
                int min = 0;
                for (int i = 0; i < x - 1; i++) {
                        if (was[i])
                                continue;
                        if (i > 0 && !div1[i - 1] && !was[i - 1])
                                div1[i] = true;
                        else
                                min++;
                }
                out.print(min + " " + max);

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