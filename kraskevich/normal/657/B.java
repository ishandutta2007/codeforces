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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    long binPow(long x, long n, long mod) {
        long res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }

    long inv(long x, long mod) {
        return binPow(x, mod - 2, mod);
    }

    final long MOD1 = 1000 * 1000 * 1000 + 7;
    final long MOD2 = 1000 * 1000 + 3;


    long correctMod(long x, long mod) {
        return (x % mod + mod) % mod;
    }


    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        long k = in.nextLong();
        long[] c = new long[n + 1];
        for (int i = 0; i <= n; i++)
            c[i] = in.nextLong();
        long val1 = 0;
        long val2 = 0;
        for (int i = n; i >= 0; i--) {
            val1 = (val1 * 2 + correctMod(c[i], MOD1)) % MOD1;
            val2 = (val2 * 2 + correctMod(c[i], MOD2)) % MOD2;
        }
        long res = 0;
        long pow1 = 1;
        long pow2 = 1;
        for (int i = 0; i <= n; i++) {
            long i1 = inv(pow1, MOD1);
long x1 = c[i] - val1 * i1;
            x1 = correctMod(x1, MOD1);
            long i2 = inv(pow2, MOD2);
long x2 = c[i] - val2 * i2;
            x2 = correctMod(x2, MOD2);
            if (x1 == 0 && i == n)
                continue;
            if (correctMod(x1, MOD2) == x2 && -k <= x1 && x1 <= k) {
                res++;
                } else if (x1 != 0 && correctMod(-MOD1 + x1, MOD2) == x2 && -k <= -MOD1 + x1 && -MOD1 + x1 <= k) {
                res++;
                }
            pow1 = pow1 * 2 % MOD1;
            pow2 = pow2 * 2 % MOD2;
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}