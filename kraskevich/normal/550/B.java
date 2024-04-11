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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();
        int r = in.nextInt();
        int x = in.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++)
            c[i] = in.nextInt();
        int res = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (Integer.bitCount(mask) < 2)
                continue;
            int mn = (int) 1e9;
            int mx = 0;
            int sum = 0;
            for (int i = 0; i < n; i++)
                if ((mask & (1 << i)) != 0) {
                    sum += c[i];
                    mn = Math.min(mn, c[i]);
                    mx = Math.max(mx, c[i]);
                }
            if (mx - mn >= x && l <= sum && sum <= r)
                res++;
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

}