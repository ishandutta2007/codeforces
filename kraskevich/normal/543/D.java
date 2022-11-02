import java.util.ArrayList;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    final long MOD = 1000 * 1000 * 1000 + 7;

    long binPow(long x, long n) {
        long res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }

    long inverse(long x) {
        return binPow(x, MOD - 2);
    }

    ArrayList<Integer>[] g;
    long[] dp;

    void dfs1(int v) {
        dp[v] = 1;
        for (int to : g[v]) {
            dfs1(to);
            dp[v] = dp[v] * (dp[to] + 2) % MOD;
        }
        dp[v] = (dp[v] - 1 + MOD) % MOD;
    }

    class Num {
        long prod;
        int zeros;

        Num(long prod, int zeros) {
            this.prod = prod;
            this.zeros = zeros;
        }

        void mul(long p, int z) {
            if (z == 0) {
                prod *= p;
                prod %= MOD;
            } else {
                zeros += z;
            }
        }

        long get() {
            if (zeros != 0)
                return 0;
            return prod;
        }
    }

    long[] res;

    void dfs2(int v, long fromLow) {
        fromLow = (fromLow + 1) % MOD;
        Num cur = new Num(fromLow, 0);
        for (int to : g[v]) {
            long p = (2 + dp[to]) % MOD;
            int z = p == 0 ? 1 : 0;
            cur.mul(p, z);
        }
        res[v] = cur.get();
        for (int to : g[v]) {
            long p = (2 + dp[to]) % MOD;
            if (p != 0)
                p = inverse(p);
            int z = p == 0 ? 1 : 0;
            cur.mul(p, -z);
            dfs2(to, cur.get());
            cur.mul((2 + dp[to]) % MOD, z);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        dp = new long[n];
        res = new long[n];
        for (int i = 1; i < n; i++) {
            int p = in.nextInt() - 1;
            g[p].add(i);
        }
        dfs1(0);
        dfs2(0, 0);
        for (int i = 0; i < n; i++)
            out.print(res[i] + " ");
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