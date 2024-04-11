import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.util.HashMap;

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
        private static final int MODULO = 1000000007;

        private static long powMod(long x, long y) {
            long z = 1;
            for (; y != 0; y >>= 1) {
                if (y % 2 == 1) z = z * x % MODULO;
                x = x * x % MODULO;
            }
            return z;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            ArrayList<Integer> times = new ArrayList<Integer>();
            ArrayList<Integer> primes = new ArrayList<Integer>();
            int n = in.nextInt();
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt();
                if (!map.containsKey(a)) {
                    map.put(a, primes.size());
                    primes.add(a);
                    times.add(0);
                }
                int index = map.get(a);
                times.set(index, times.get(index) + 1);
            }

            n = primes.size();
            long[] front = new long[n + 1];
            long[] back = new long[n + 1];

            front[0] = 1;
            for (int i = 0; i < n; ++i) {
                front[i + 1] = front[i] * (times.get(i) + 1) % (MODULO - 1);
            }

            back[n] = 1;
            for (int i = n - 1; i >= 0; --i) {
                back[i] = back[i + 1] * (times.get(i) + 1) % (MODULO - 1);
            }

            long ans = 1L;
            for (int i = 0; i < n; ++i) {
                int p = primes.get(i);
                long prod = 1;
                for (int j = 0; j < times.get(i); ++j) {
                    prod = prod * p % MODULO;
                    ans = ans * (powMod(prod, front[i] * back[i + 1] % (MODULO - 1))) % MODULO;
                }
            }

            out.println(ans);
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