import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private static final int MAX_LENGTH = 20;
        private static final int MODULO = 1000000007;

        private int powMod(long x, int y) {
            long res = 1;
            for (; y != 0; y >>= 1) {
                if (y % 2 == 1) {
                    res = res * x % MODULO;
                }
                x = x * x % MODULO;
            }
            return (int) res;
        }

        private void go(int[] a, int depth) {
            if (a.length == 2) {
                a[0] = (int) ((a[0] + a[1] * (long) a[0]) % MODULO);
                return;
            }

            int[] u = new int[1 << (depth - 1)];
            int[] v = new int[1 << (depth - 1)];

            for (int i = 0; i < (1 << (depth - 1)); ++i) {
                u[i] = a[i + (1 << (depth - 1))];
                v[i] = (int) ((a[i] + u[i] + a[i] * (long) u[i]) % MODULO);
            }

            go(u, depth - 1);
            go(v, depth - 1);

            for (int i = 0; i < (1 << (depth - 1)); ++i) {
                a[i] = (v[i] - u[i]) % MODULO;
                a[i + (1 << (depth - 1))] = u[i];
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[1 << MAX_LENGTH];
            for (int i = 0; i < n; ++i) {
                ++a[in.nextInt()];
            }

            for (int i = 0; i < (1 << MAX_LENGTH); ++i) {
                a[i] = (powMod(2, a[i]) - 1) % MODULO;
            }

            go(a, MAX_LENGTH);

            int answer = (a[0] + MODULO) % MODULO;

            out.println(answer);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}