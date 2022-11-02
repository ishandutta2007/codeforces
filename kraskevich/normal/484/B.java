import java.io.*;
import java.util.StringTokenizer;

public class Task {
    final int N = 1_000_000 + 10;

    public void run() throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        boolean[] was = new boolean[N];
        for (int i = 0; i < n; i++) {
            int a = in.nextInt();
            was[a] = true;
        }
        int res = 0;
        int[] last = new int[N];
        int prev = 0;
        for (int i = 1; i < N; i++) {
            if (was[i])
                prev = i;
            last[i] = prev;
        }
        for (int i = 2; i < N; i++)
            if (was[i])
                for (int j = 1; i * j < N; j++) {
                    int border = Math.min(N - 1, i * j + i - 1);
                    int biggest = last[border];
                    res = Math.max(res, biggest % i);
                }
        out.println(res);
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