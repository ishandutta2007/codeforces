import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long n = in.nextLong();
        long m = in.nextLong();
        long lo = 0;
        long hi = (long) 1e18;
        while (hi - lo > 1) {
            long mid = (lo + hi) / 2;
            long d2 = mid / 2;
            long d3 = mid / 3;
            long d6 = mid / 6;
            long ud2 = d2 - d6;
            long ud3 = d3 - d6;
            long newN = Math.max(0L, n - ud2);
            long newM = Math.max(0L, m - ud3);
            if (newN + newM <= d6) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        out.println(hi);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}