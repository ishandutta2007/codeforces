import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class Task {

    public void solve(FastScanner in, PrintWriter out) throws IOException {
        List<List<Integer>> lists = new ArrayList<>();
        for (int i = 0; i < 3; i++)
            lists.add(new ArrayList<Integer>());
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int t = in.nextInt();
            t--;
            lists.get(t).add(i + 1);
        }
        int count = Math.min(Math.min(lists.get(0).size(), lists.get(1).size()), lists.get(2).size());
        out.println(count);
        for (int i = 0; i < count; i++)
            out.println(lists.get(0).get(i) + " " + lists.get(1).get(i) + " " + lists.get(2).get(i));
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