import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.io.InputStreamReader;

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

    long calc(long n) {
        long k = 2;
        long res = 0;
        while (k * k * k <= n) {
            res += n / (k * k * k);
            k++;
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long m = in.nextLong();
        long lo = 0;
        long hi = (long) 1e17;
        while (hi - lo > 1) {
            long mid = (lo + hi) / 2;
            if (calc(mid) >= m)
                hi = mid;
            else
                lo = mid;
        }
        if (calc(hi) == m)
            out.println(hi);
        else
            out.println(-1);
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