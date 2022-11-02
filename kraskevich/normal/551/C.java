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
        int n = in.nextInt();
        int m = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextLong();
        long low = 0;
        long high = (long) 1e18;
        while (high - low > 1) {
            long mid = (low + high) / 2;
            if (countStudents(a.clone(), mid, m) <= m)
                high = mid;
            else
                low = mid;
        }
        out.println(high);
    }

    long countStudents(long[] a, long time, int m) {
        int n = a.length;
        int last = n - 1;
        int cnt = 0;
        for (;;) {
            while (last >= 0 && a[last] == 0)
                last--;
            if (last < 0)
                break;
            cnt++;
            if (cnt > m)
                break;
            long hits = time - last - 1;
            if (hits <= 0)
                return m + 1;
            for (;;) {
                if (hits == 0)
                    break;
                if (last < 0)
                    break;
                long d = Math.min(hits, a[last]);
                hits -= d;
                a[last] -= d;
                if (a[last] == 0)
                    last--;
            }
        }
        return cnt;
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