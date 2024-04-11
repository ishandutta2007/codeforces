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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    int n;
    long[] a;
    int[] go;
    int[] dpFirst;
    int[] cntFirst;
    int[] dpSecond;
    int[] cntSecond;

    int calc(long b) {
        long tot = 0;
        for (int i = 0; i < n; i++)
            tot += a[i];
        if (tot <= b)
            return 1;
        int res = n;
        long curSum = 0;
        for (int l = 0, r = 0; l < a.length; l++) {
            while (r < a.length && curSum + a[r] <= b) {
                curSum += a[r];
                r++;
            }
            go[l] = r;
            curSum -= a[l];
        }
        for (int i = 2 * n - 1; i >= n; i--) {
            dpFirst[i] = i;
            cntFirst[i] = 0;
            dpSecond[i] = go[i];
            cntSecond[i] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            dpFirst[i] = dpFirst[go[i]];
            cntFirst[i] = cntFirst[go[i]] + 1;
            dpSecond[i] = dpSecond[go[i]];
            cntSecond[i] = cntSecond[go[i]] + 1;
            if (dpFirst[i] - n >= i)
                res = Math.min(res, cntFirst[i]);
            if (dpSecond[i] - n >= i)
                res = Math.min(res, cntSecond[i]);
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        int q = in.nextInt();
        a = new long[2 * n];
        dpFirst = new int[2 * n];
        cntFirst = new int[2 * n];
        dpSecond = new int[2 * n];
        cntSecond = new int[2 * n];
        go = new int[2 * n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextLong();
        for (int i = n; i < 2 * n; i++)
            a[i] = a[i - n];
        for (int i = 0; i < q; i++) {
            long b = in.nextLong();
            out.println(calc(b));
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}