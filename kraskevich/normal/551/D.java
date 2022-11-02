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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    long mod;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long n = in.nextLong();
        long k = in.nextLong();
        long bits = in.nextLong();
        mod = in.nextLong();
        if (bits < 63 && k >= (1L << bits)) {
            out.println(0);
            return;
        }
        long res = 1 % mod;
        for (int b = 0; b < bits; b++) {
            long cur = getFib(n);
            if (b < 63 && (k & (1L << b)) != 0) {
                cur = (binPow(2, n) - cur + mod) % mod;
            }
            res = res * cur % mod;
        }
        out.print(res);
    }

    class Matrix {
        long[][] a;

        Matrix() {
            a = new long[2][2];
        }

        Matrix mult(Matrix m) {
            Matrix res = new Matrix();
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        res.a[i][j] = (res.a[i][j] + a[i][k] * m.a[k][j]) % mod;
            return res;
        }
    }

    long getFib(long n) {
        n++;
        Matrix m = new Matrix();
        m.a[0][0] = 1 % mod;
        m.a[1][0] = 1 % mod;
        m.a[0][1] = 1 % mod;
        m = pow(m, n);
        return m.a[0][0];
    }

    Matrix pow(Matrix x, long n) {
        Matrix res = new Matrix();
        res.a[0][0] = 1 % mod;
        res.a[1][1] = 1 % mod;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                res = res.mult(x);
            x = x.mult(x);
        }
        return res;
    }

    long binPow(long x, long n) {
        long res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                res = res * x % mod;
            x = x * x % mod;
        }
        return res;
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