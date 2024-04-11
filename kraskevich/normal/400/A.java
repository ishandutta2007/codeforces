import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int tests = in.nextInt();
                for (int t = 0; t < tests; t++) {
                        String s = in.nextToken();
                        ArrayList<String> res = new ArrayList<>();
                        for (int a = 1; a <= 12; a++) {
                                if (12 % a != 0)
                                        continue;
                                int b = 12 / a;
                                boolean ok = false;
                                for (int pos = 0; pos < b; pos++) {
                                        boolean now = true;
                                        for (int i = 0; i < a; i++) {
                                                int cur = i * b + pos;
                                                if (s.charAt(cur) != 'X')
                                                        now = false;
                                        }
                                        ok |= now;
                                }
                                if (ok)
                                        res.add(Integer.toString(a) + "x" + Integer.toString(b));
                        }
                        out.print(res.size() + " ");
                        for (String val : res)
                                out.print(val + " ");
                        out.println();
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