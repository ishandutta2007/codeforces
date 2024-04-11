import java.io.*;
import java.util.StringTokenizer;

public class Task {
    long[] init;
    long[] a;
    boolean[] interesting;

    long getMin(int left, int right) {
        long res = Integer.MAX_VALUE;
        for (int i = left; i <= right; i++)
            res = Math.min(res, a[i]);
        return res;
    }

    long getMax(int left, int right) {
        long res = Integer.MIN_VALUE;
        for (int i = left; i <= right; i++)
            res = Math.max(res, a[i]);
        return res;
    }

    public void run() throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        init = new long[n];
        for (int i = 0; i < n; i++)
            init[i] = in.nextLong();
        interesting = new boolean[n];
        interesting[0] = true;
        interesting[n - 1] = true;
        for (int i = 1; i < n - 1; i++) {
            if (init[i] <= init[i - 1] && init[i] < init[i + 1]
                    || init[i] < init[i - 1] && init[i] <= init[i + 1]
                    || init[i] >= init[i - 1] && init[i] > init[i + 1]
                    || init[i] > init[i - 1] && init[i] >= init[i + 1]) {
                interesting[i] = true;
                interesting[i - 1] = true;
                interesting[i + 1] = true;
            }
        }
        int total = 0;
        a = new long[n];
        for (int i = 0; i < n; i++)
            if (interesting[i])
                a[total++] = init[i];
        long[] dp = new long[total + 1];
        dp[0] = 0;
        for (int left = 0; left < n; left++) {
            for (int right = left + 1; right <= Math.min(left + 20, total); right++) {
                long min = getMin(left, right - 1);
                long max = getMax(left, right - 1);
                dp[right] = Math.max(dp[right], dp[left] + max - min);
            }
        }
        out.println(dp[total]);
        out.flush();
    }

    public static void main(String[] args) throws IOException {
        new Task().run();
    }

    class FastScanner {
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