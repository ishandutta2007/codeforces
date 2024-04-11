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
                int a = in.nextInt();
                int b = in.nextInt();
                for (int dx1 = 1; dx1 < a; dx1++)
                        for (int dx2 = 1; dx2 < b; dx2++) {
                                int dy1 = root(a * a - dx1 * dx1);
                                int dy2 = root(b * b - dx2 * dx2);
                                if (dy1 == -1 || dy2 == -1)
                                        continue;
                                if (dx1 * dx2 != dy1 * dy2)
                                        continue;
                                if (dy1 == dy2)
                                        continue;
                                out.println("YES");
                                out.println("0 0");
                                out.println(dx1 + " " + dy1);
                                out.println(-dx2 + " " + dy2);
                                return;
                        }
                out.println("NO");
        }

        int root(long a) {
                long l = 0;
                long r = a;
                while (l < r) {
                        long m = (l + r) / 2;
                        if (m * m >= a)
                                r = m;
                        else
                                l = m + 1;
                }
                if (l * l == a)
                        return (int)l;
                return -1;
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