import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                long n = in.nextLong();
                long sx = in.nextLong();
                long sy = in.nextLong();
                long dx = in.nextLong();
                long dy = in.nextLong();
                long t = in.nextLong();
                //long[] ans = bruteForce(n, sx, sy, dx, dy, t);
                sx--;
                sy--;
                long[][] base = {
                        {2, 1, 1, 0, 1, 2},
                        {1, 2, 0, 1, 1, 2},
                        {1, 1, 1, 0, 1, 2},
                        {1, 1, 0, 1, 1, 2},
                        {0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 0, 0, 1}};
                Matrix init = new Matrix(base, n);
                Matrix res = init.power(init, t);
                /*for (int i = 0; i < 6; i++) {
                        for (int j = 0; j < 6; j++)
                                out.print(res.value[i][j] + " ");
                        out.println();
                }  */
                long rx, ry;
                rx = res.value[0][0] * sx + res.value[0][1] * sy + res.value[0][2] * dx + res.value[0][3] * dy +
                        res.value[0][4] * 0 + res.value[0][5];
                ry = res.value[1][0] * sx + res.value[1][1] * sy + res.value[1][2] * dx + res.value[1][3] * dy +
                        res.value[1][4] * 0 + res.value[1][5];
                sx = rx;
                sy = ry;
                sx %= n;
                sx += n;
                sx %= n;
                sy %= n;
                sy += n;
                sy %= n;
                sx++;
                sy++;
                //out.println(ans[0] + " " + ans[1]);
                out.println(sx + " " + sy);
        }

        }

class Matrix {
        long mod;
        long[][] value;
        final static int n = 6;

        Matrix(long[][] value, long mod) {
                this.value = value;
                this.mod = mod;
        }

        Matrix getOne() {
                long[][] one = new long[n][n];
                for (int i = 0; i < n; i++)
                        one[i][i] = 1;
                return new Matrix(one, mod);
        }

        Matrix multiply(Matrix other) {
                Matrix res = new Matrix(new long[n][n], mod);
                for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                                for (int k = 0; k < n; k++) {
                                        res.value[i][j] += value[i][k] * other.value[k][j] % mod;
                                        res.value[i][j] %= mod;
                                }
                return res;
        }

        Matrix power(Matrix base, long pow) {
                Matrix res = getOne();
                while (pow > 0) {
                        if (pow % 2 == 1)
                                res = base.multiply(res);
                        base = base.multiply(base);
                        pow /= 2;
                }
                return res;
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        public long nextLong() {
                return Long.parseLong(nextToken());
        }

        }