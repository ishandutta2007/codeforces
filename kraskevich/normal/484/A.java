import java.io.*;
import java.util.StringTokenizer;

public class Task {
    public static void main(String[] args) throws IOException {
        new Task().run();
    }

    public void run() throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            long left = in.nextLong();
            long right = in.nextLong();
            long pos = 62;
            while (pos >= 0 && ((1L << pos) & left) == ((1L << pos) & right))
                pos--;
            if (pos < 0)
                out.println(left);
            else if ((right & ((1L << pos) - 1)) == ((1L << pos) - 1))
                out.println(right);
            else
                out.println((left >> pos << pos) + (1L << pos) - 1);
        }
        out.flush();
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