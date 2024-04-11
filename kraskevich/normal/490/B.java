import java.io.*;
import java.util.*;


public class Task {
    final int MAX_ID = 1_000_000 + 10;
    List<List<Integer>> g = new ArrayList<>();
    List<Integer> order = new ArrayList<>();
    int[] prev = new int[MAX_ID];
    int[] next = new int[MAX_ID];
    int[] childOf = new int[MAX_ID];

    void dfs(int i, int toPrint) {
        if (prev[i] != 0)
            dfs(childOf[toPrint], prev[i]);
        order.add(toPrint);
    }

    public void solve(FastScanner in, PrintWriter out) throws IOException {
        for (int i = 0; i < MAX_ID; i++)
            g.add(new ArrayList<Integer>());
        int n = in.nextInt();
        int start = 0;
        Set<Integer> all = new HashSet<>();
        Set<Integer> wasPrev = new HashSet<>();
        for (int i = 0; i < n; i++) {
            prev[i] = in.nextInt();
            next[i] = in.nextInt();
            childOf[next[i]] = i;
            all.add(prev[i]);
            all.add(next[i]);
            if (next[i] != 0 && prev[i] != 0)
                g.get(next[i]).add(prev[i]);
            wasPrev.add(prev[i]);
        }
        for (int v : all)
            if (!wasPrev.contains(v))
                start = v;
        dfs(childOf[0], start);
        for (int v : order)
            out.print(v + " ");
        out.println();
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