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

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long base = in.nextLong();
        long want = in.nextLong();
        if (base == 2) {
            out.println("YES");
            return;
        }
        long maxPow = 0;
        while (lpow(base, maxPow) <= want)
            maxPow++;
        for (int mask = 0; mask < (1 << maxPow); mask++) {
            long curP = 1;
            long curM = want;
            for (int i = 0; i < maxPow; i++) {
                if ((mask & (1 << i)) != 0)
                    curM += curP;
                curP *= base;
            }
            boolean ok = true;
            for (int i = 0; i < 30; i++) {
                long rem = curM % base;
                curM /= base;
                if (rem == 1 && (mask & (1 << i)) != 0)
                    ok = false;
                if (rem != 0 && rem != 1)
                    ok = false;
            }
            if (ok) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");
    }
    
    long lpow(long x, long n) {
        long y = 1;
        for (int i = 0; i < n; i++)
            y *= x;
        return y;
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