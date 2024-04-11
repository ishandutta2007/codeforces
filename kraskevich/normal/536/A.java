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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    final long INF = (long) 1e6 + 10;

    long A;
    long B;

    boolean check(long low, long cnt, long maxBites, long biteSize) {
        cnt++;
        long fst = A + (low - 1) * B;
        long snd = fst + (cnt - 1) * B;
        long sum = (fst + snd) * cnt / 2;
        long tot = sum / biteSize + (sum % biteSize == 0 ? 0 : 1);
        tot = Math.max(tot, snd);
        return tot <= maxBites;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        A = in.nextLong();
        B = in.nextLong();
        long n = in.nextLong();
        for (int i = 0; i < n; i++) {
            long low = in.nextLong();
            long cnt = in.nextLong();
            long step = in.nextLong();
            long L = -1;
            long R = INF;
            while (R - L > 1) {
                long mid = (L + R) / 2;
                if (check(low, mid, cnt, step))
                    L = mid;
                else
                    R = mid;
            }
            if (L >= 0)
                L += low;
            out.println(L);
        }
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
                // ignore
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