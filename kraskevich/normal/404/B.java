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
                long a = readDouble(in);
                long d = readDouble(in);
                long n = in.nextInt();
                for (long i = 1; i <= n; i++) {
                        long cur = i * d;
                        cur %= 4 * a;
                        int pos = (int)(cur / a);
                        long x = 0;
                        long y = 0;
                        switch (pos) {
                                case 0 : x = cur; y = 0; break;
                                case 1 : x = a; y = cur - a; break;
                                case 2 : x = 3 * a - cur; y = a; break;
                                case 3 : x = 0; y = 4 * a - cur; break;
                        }
                        out.format("%.6f %.6f%n", x / 10000.0, y / 10000.0);
                }
        }

        long readDouble(FastScanner in) {
                char[] s = in.nextToken().toCharArray();
                long before = 0;
                long after = 0;
                int i = 0;
                while (i < s.length && s[i] != '.') {
                        int cur = s[i] - '0';
                        before = before * 10 + cur;
                        i++;
                }
                i++;
                long cnt = 4;
                while (i < s.length) {
                        int cur = s[i] - '0';
                        after = after * 10 + cur;
                        i++;
                        cnt--;
                }
                while (cnt > 0) {
                        cnt--;
                        after *= 10;
                }
                return before * 10000L + after;
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