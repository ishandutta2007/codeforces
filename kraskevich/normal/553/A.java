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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    final long MOD = 1_000_000_000 + 7;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] cnt = new int[n];
        int m = 0;
        for (int i = 0; i < n; i++) {
            cnt[i] = in.nextInt();
            m += cnt[i];
        }
        long[][] c = new long[2 * m + 2][2 * m + 2];
        c[0][0] = 1;
        for (int i = 1; i <= 2 * m + 1; i++)
            for (int j = 0; j <= i; j++) {
                c[i][j] = c[i - 1][j];
                if (j > 0) {
                    c[i][j] = (c[i][j] + c[i - 1][j - 1]) % MOD;
                }
            }
        int tot = 0;
        long res = 1;
        for (int i = 0; i < n; i++) {
            long add = 0;
            if (tot != 0)
                for (int p = 0; p < cnt[i]; p++)
                    add = (add + res * c[tot + p - 1][p]) % MOD;
            else
                add = 1;
            res = add;
            tot += cnt[i];
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