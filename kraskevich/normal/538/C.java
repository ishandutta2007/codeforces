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
        int[] d = new int[m];
        int[] h = new int[m];
        for (int i = 0; i < m; i++) {
            d[i] = in.nextInt();
            h[i] = in.nextInt();
        }
        boolean ok = true;
        for (int i = 1; i < m; i++) {
            if (Math.abs(h[i] - h[i - 1]) > d[i] - d[i - 1])
                ok = false;
        }
        if (!ok) {
            out.println("IMPOSSIBLE");
            return;
        }
        int res = Math.max(h[0] + d[0] - 1, h[m - 1] + n - d[m - 1]);
        for (int i = 1; i < m; i++)
            res = Math.max(res, (d[i] - d[i - 1] + h[i] + h[i - 1]) / 2);
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

}