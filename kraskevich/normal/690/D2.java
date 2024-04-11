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
		TaskD2 solver = new TaskD2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD2 {

    final long MOD = 1_000_003;

    long binPow(long x, long n) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = res * x % MOD;
            x = x * x % MOD;
            n /= 2;
        }
        return res;
    }

    long inv(long x) {
        return binPow(x, MOD - 2);
    }

    long fac(long n) {
        long res = 1;
        for (int i = 1; i <= n; i++)
            res = res * i % MOD;
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        long res = fac(n + k);
        res = res * inv(fac(k)) % MOD;
        res = res * inv(fac(n)) % MOD;
        out.println((res - 1 + MOD) % MOD);
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