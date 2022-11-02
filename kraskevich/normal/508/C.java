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
    final int N = 333;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int m = in.nextInt();
        int t = in.nextInt();
        int r = in.nextInt();
        int[] w = new int[m];
        for (int i = 0; i < m; i++)
            w[i] = in.nextInt();
        if (r > t) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < m; i++)
            w[i] += N;
        int[] cnt = new int[10 * N];
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = w[i] - (r - cnt[w[i]]) + 1; j <= w[i]; j++) {
                res++;
                for (int k = j; k < j + t; k++)
                    cnt[k]++;
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