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
                int n = in.nextInt();
                int k = in.nextInt();
                if (n == 1) {
                        if (k == 0)
                                out.println(1);
                        else
                                out.println(-1);
                        return;
                }
                long min = n / 2;
                if (k < min) {
                        out.println(-1);
                        return;
                }
                int pairs = n / 2;
                int rem = pairs - 1;
                int first = k - rem;
                out.print(first + " " + 2 * first + " ");
                for (int i = 0; i < rem; i++)
                        out.print((2 * i + 1 + 2 * first) + " " + (2 * i + 2 + 2 * first) + " ");
                if (n % 2 == 1)
                        out.println(1000 * 1000 * 1000);
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