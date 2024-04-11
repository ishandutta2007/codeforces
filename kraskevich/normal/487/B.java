import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Task {
    final int INF = (int)1e9 + 10;

    class SegmentTree {
        int[] data;
        int size;

        SegmentTree(int size) {
            data = new int[size * 4 + 10];
            Arrays.fill(data, INF);
            this.size = size;
        }

        void put(int i, int tl, int tr, int pos, int val) {
            if (tl == tr) {
                data[i] = val;
                return;
            }
            int m = (tl + tr) / 2;
            if (pos <= m)
                put(2 * i + 1, tl, m, pos, val);
            else
                put(2 * i + 2, m + 1, tr, pos, val);
            data[i] = Math.min(data[2 * i + 1], data[2 * i + 2]);
        }

        void put(int pos, int val) {
            put(0, 0, size - 1, pos, val);
        }

        int get(int i, int tl, int tr, int l, int r) {
            if (l == tl && r == tr)
                return data[i];
            int m = (tl + tr) / 2;
            int sl = INF;
            int sr = INF;
            if (l <= m)
                sl = get(2 * i + 1, tl, m, l, Math.min(r, m));
            if (r > m)
                sr = get(2 * i + 2, m + 1, tr, Math.max(m + 1, l), r);
            return Math.min(sl, sr);
        }

        int get(int l, int r) {
            return get(0, 0, size - 1, l, r);
        }
    }

    public void solve(FastScanner in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int s = in.nextInt();
        int len = in.nextInt();
        int[] a = new int[n];
        SegmentTree min = new SegmentTree(n);
        SegmentTree max = new SegmentTree(n);
        SegmentTree dpTree = new SegmentTree(n + 1);
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            min.put(i, a[i]);
            max.put(i, -a[i]);
        }
        int[] dp = new int[n + 1];
        dpTree.put(0, 0);
        Arrays.fill(dp, INF);
        dp[0] = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (-max.get(l, r) - min.get(l, r) > s)
                l++;
            int first = l;
            int last = r - len + 1;
            if (first <= last)
                dp[r + 1] = dpTree.get(first, last) + 1;
            dpTree.put(r + 1, dp[r + 1]);
        }
        int res = dp[n];
        if (res >= INF)
            res = -1;
        out.println(res);
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