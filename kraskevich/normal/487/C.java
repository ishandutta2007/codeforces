import java.io.*;
import java.util.StringTokenizer;


public class Task {

    private boolean isPrimeOrOne(int n) {
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    int binPow(long x, long n, int mod) {
        long res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                res = res * x % mod;
            x = x * x % mod;
        }
        return (int)res;
    }

    public void solve(FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        if (n == 1) {
            out.println("YES\n1\n");
        } else if (n == 4) {
            out.println("YES");
            out.println("1\n3\n2\n4\n");
        } else if (isPrimeOrOne(n)) {
            out.println("YES");
            //int prod = 1;
            int[] res = new int[n];
            res[0] = 1;
            res[n - 1] = n;
            long have = 1;
            for (int i = 2; i <= n - 1; i++) {
                long want = i;
                long cur = want * binPow(have, n - 2, n) % n;
                res[i - 1] = (int)cur;
                have = have * cur % n;
            }
            for (int i = 0; i < n; i++)
                out.println(res[i]);
            /*for (int i = 0; i < n; i++) {
                prod *= res[i];
                prod %= n;
                out.print(prod + " ");
            }*/
        } else {
            out.println("NO");
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        for (int i = 0; i < t; i++)
            new Task().solve(in, out);
        out.flush();
    }

    static class FastScanner {
        private StringTokenizer tokenizer;
        private BufferedReader reader;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                String line = reader.readLine();
                if (line == null)
                    throw new IOException();
                tokenizer = new StringTokenizer(line);
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public void close() {
            try {
                reader.close();
            } catch (IOException e) {
                // ignore
            }
        }
    }
}