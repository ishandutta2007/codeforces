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
 * @author Igor Kraskevich
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    final long INF = (long) 3e9;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        long last = -INF;
        long[] x = new long[n];
        long[] h = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextLong();
            h[i] = in.nextLong();
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] - h[i] > last) {
                last = x[i];
                res++;
            } else if (i == n - 1 || x[i] + h[i] < x[i + 1]) {
                last = x[i] + h[i];
                res++;
            } else {
                last = x[i];
            }
        }
        out.println(res);
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}