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
		TaskD3 solver = new TaskD3();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD3 {

    final long MOD = 1_000_003;

    long mul(long a, long b) {
        return a * b % MOD;
    }

    long add(long a, long b) {
        return (a + b) % MOD;
    }

    long[][] mul(long[][] a, long[][] b) {
        int N = a.length;
        int K = a[0].length;
        int M = b[0].length;
        long[][] res = new long[N][M];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                for (int k = 0; k < K; k++)
                    res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
        return res;
    }

    long[][] binPow(long[][] x, long n) {
        long[][] res = new long[x.length][x.length];
        for (int i = 0; i < res.length; i++)
            res[i][i] = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = mul(res, x);
            x = mul(x, x);
            n /= 2;
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int c = in.nextInt();
        int w = in.nextInt();
        int h = in.nextInt();
        long[][] x = new long[w + 1][w + 1];
        for (int j = 0; j <= w; j++)
            x[0][j] = 1;
        for (int i = 1; i <= w; i++)
            x[i][i - 1] = h;
        long[][] a = binPow(x, c);
        long[][] v = new long[w + 1][1];
        v[0][0] = 1;
        long[][] res = mul(a, v);
        long ans = 0;
        for (int i = 0; i <= w; i++)
            ans = add(ans, res[i][0]);
        out.println(ans);
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