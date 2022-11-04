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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        private int[] dsuStart;
        private int[] dsuEnd;
        private int dsuLabel;
        private Edge[] first;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n, q;
            n = in.nextInt();
            q = in.nextInt();
            long[] color = new long[n];
            for (int i = 0; i < n; ++i) {
                color[i] = 1L << in.nextLong();
            }

            first = new Edge[n];
            for (int i = 0; i < n - 1; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                new Edge(u, v);
                new Edge(v, u);
            }

            dsuLabel = 0;
            dsuStart = new int[n];
            dsuEnd = new int[n];
            dfs(0, -1);
            long[] dsuColors = new long[n];
            for (int i = 0; i < n; ++i) {
                dsuColors[dsuStart[i]] = color[i];
            }

            IntervalTree tree = new IntervalTree(dsuColors);
            while (q-- > 0) {
                int type = in.nextInt();
                int v = in.nextInt() - 1;
                if (type == 1) {
                    long c = 1L << in.nextLong();
                    tree.doCover(dsuStart[v], dsuEnd[v], c);
                } else {
                    out.println(Long.bitCount(tree.getUnion(dsuStart[v], dsuEnd[v])));
                }
            }
        }

        private void dfs(int x, int father) {
            dsuStart[x] = dsuLabel++;
            for (Edge e = first[x]; e != null; e = e.next) {
                if (e.to != father) {
                    dfs(e.to, x);
                }
            }
            dsuEnd[x] = dsuLabel - 1;
        }

        class Edge {
            int to;
            Edge next;

            Edge(int from, int to) {
                this.to = to;
                this.next = first[from];
                first[from] = this;
            }

        }

        static class IntervalTree {
            int size;
            long[] val;
            long[] cover;

            IntervalTree(long[] initialColor) {
                int length = initialColor.length;

                this.size = length;
                val = new long[length * 4 + 100];
                cover = new long[length * 4 + 100];

                initColors(0, length - 1, 1, initialColor);
            }

            void initColors(int left, int right, int x, long[] color) {
                if (left == right) {
                    val[x] = color[left];
                    return;
                }

                int mid = (left + right) >> 1;
                initColors(left, mid, x * 2, color);
                initColors(mid + 1, right, x * 2 + 1, color);
                val[x] = val[x * 2] | val[x * 2 + 1];
            }

            void pushDown(int x) {
                if (cover[x] != 0) {
                    cover[x * 2] = cover[x * 2 + 1] = cover[x];
                    val[x * 2] = val[x * 2 + 1] = cover[x];
                    cover[x] = 0;
                }
            }

            long getUnion(int left, int right, int l, int r, int x) {
                if (l <= left && r >= right) {
                    return val[x];
                }
                pushDown(x);
                int mid = (left + right) >> 1;

                long ret = 0;
                if (l <= mid) ret |= getUnion(left, mid, l, r, x * 2);
                if (r > mid) ret |= getUnion(mid + 1, right, l, r, x * 2 + 1);
                return ret;
            }

            long getUnion(int left, int right) {
                return getUnion(0, size - 1, left, right, 1);
            }

            void doCover(int left, int right, int l, int r, int x, long newColor) {
                if (l <= left && r >= right) {
                    cover[x] = val[x] = newColor;
                    return;
                }

                pushDown(x);

                int mid = (left + right) >> 1;
                if (l <= mid) doCover(left, mid, l, r, x * 2, newColor);
                if (r > mid) doCover(mid + 1, right, l, r, x * 2 + 1, newColor);

                val[x] = val[x * 2] | val[x * 2 + 1];
            }

            void doCover(int l, int r, long newColor) {
                doCover(0, size - 1, l, r, 1, newColor);
            }

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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}