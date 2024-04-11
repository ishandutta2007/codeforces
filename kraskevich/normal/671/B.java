import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    int n;
    long[] initial;
    long k;
    long total;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        Random random = new Random();
        n = in.nextInt();
        k = in.nextLong();
        initial = new long[n];
        long min = Integer.MAX_VALUE;
        long max = 0;
        for (int i = 0; i < n; i++) {
            initial[i] = in.nextInt();
            total += initial[i];
            max = Math.max(max, initial[i]);
            min = Math.min(min, initial[i]);
        }
        long minRich = (total + n - 1) / n;
        long low = minRich - 1;
        long high = max;
        while (high - low > 1) {
            long mid = (low + high) / 2;
            if (taken(mid) <= k)
                high = mid;
            else
                low = mid;
        }
        long richest = high;
        low = min;
        high = richest + 1;
        while (high - low > 1) {
            long mid = (low + high) / 2;
            if (given(mid) <= k)
                low = mid;
            else
                high = mid;
        }
        long poorest = low;
        if (poorest == richest && total % n != 0)
            poorest--;
out.println(richest - poorest);
    }

    long taken(long gap) {
        long sum = 0;
        for (int i = 0; i < n; i++)
            sum += Math.max(0, initial[i] - gap);
        return sum;
    }

    long given(long gap) {
        long sum = 0;
        for (int i = 0; i < n; i++)
            sum += Math.max(0, gap - initial[i]);
        return sum;
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