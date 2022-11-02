import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                double r = in.nextDouble();
                for (int a = 1; a <= 10; a++)
                        for (int h = 1; h <= 10; h++) {
                                double A = a / 2.0;
                                double H = h;
                                double have = A * H / Math.sqrt(A * A + H * H);
                                if (Math.abs(have - r) < 1e-6) {
                                        out.println(a + " " + h);
                                        return;
                                }
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

        public double nextDouble() {
                return Double.parseDouble(nextToken());
        }
}