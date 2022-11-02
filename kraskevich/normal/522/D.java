import java.io.*;
import java.util.*;

public class Task {

    final int INF = 1_000_000_000;

    class SegmentTree {
        int[] data;
        int size;

        SegmentTree(int size) {
            this.size = size;
            data = new int[4 * size + 10];
            Arrays.fill(data, INF);
        }

        int getMin(int i, int tl, int tr, int l, int r) {
            if (l == tl && r == tr)
                return data[i];
            int m = (tl + tr) / 2;
            int ml = INF;
            int mr = INF;
            if (l <= m)
                ml = getMin(2 * i + 1, tl, m, l, Math.min(r, m));
            if (r > m)
                mr = getMin(2 * i + 2, m + 1, tr, Math.max(l, m + 1), r);
            return Math.min(ml, mr);
        }

        int getMin(int l, int r) {
            return getMin(0, 0, size - 1, l, r);
        }

        void put(int i, int tl, int tr, int pos, int val) {
            data[i] = Math.min(data[i], val);
            if (tl == tr)
                return;
            int m = (tl + tr) / 2;
            if (pos <= m)
                put(2 * i + 1, tl, m, pos, val);
            else
                put(2 * i + 2, m + 1, tr, pos, val);
        }

        void put(int pos, int val) {
            put(0, 0, size - 1, pos, val);
        }
    }

    class Query {
        int left;
        int id;

        Query(int left, int id) {
            this.left = left;
            this.id = id;
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] ans = new int[m];
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        List<Query>[] queries = new ArrayList[n];
        for (int i = 0; i < n; i++)
            queries[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int left = in.nextInt() - 1;
            int right = in.nextInt() - 1;
            queries[right].add(new Query(left, i));
        }
        Map<Integer, Integer> last = new HashMap<>();
        SegmentTree tree = new SegmentTree(n);
        for (int i = 0; i < n; i++) {
            Integer prev = last.get(a[i]);
            if (prev != null)
                tree.put(prev, i - prev);
            last.put(a[i], i);
            for (Query q : queries[i]) {
                int min = tree.getMin(q.left, i);
                if (min == INF)
                    min = -1;
                ans[q.id] = min;
            }
        }
        for (int i = 0; i < m; i++)
            out.println(ans[i]);
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int t = 1;
        for (int i = 1; i <= t; i++)
            new Task().solve(i, in, out);
        in.close();
        out.close();
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
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                return null;
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            return null;
        }
        return line;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {

        }
    }
}