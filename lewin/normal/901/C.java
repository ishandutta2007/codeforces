import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public List<Integer>[] graph;
        public static int MODE = 0;
        public List<TaskC.Point> tt;
        public int[] p;
        public boolean[] vis;
        public int[] depth;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }

            vis = new boolean[n];
            tt = new ArrayList<>();
            p = new int[n];
            depth = new int[n];
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    dfs(i, -1);
                }
            }
            Collections.sort(tt, Comparator.comparingInt(g -> g.x));
            List<TaskC.Point> pts = new ArrayList<>();
            int lasty = n + 100;
            for (int i = tt.size() - 1; i >= 0; i--) {
                if (tt.get(i).y < lasty) {
                    lasty = tt.get(i).y;
                    pts.add(tt.get(i));
                }
            }
            int q = in.nextInt();

            TaskC.Query[] qs = new TaskC.Query[q];
            long[] ans = new long[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new TaskC.Query(in.nextInt() - 1, in.nextInt() - 1, i);
                long len = qs[i].r - qs[i].l + 1;
                ans[i] = len * (len - 1) / 2 + len;
            }
            Arrays.sort(qs, Comparator.comparingLong(g -> 1L * n * g.l + g.r));

            BITLong bx = new BITLong(n + 1010);
            BITLong by = new BITLong(n + 1010);

            int pidx = 0;
            for (int i = q - 1; i >= 0; i--) {
                int x = qs[i].l, y = qs[i].r;
                while (pidx < pts.size() && pts.get(pidx).x >= x) {
                    int up = pidx == 0 ? n + 100 : (pts.get(pidx - 1).y - 1);
                    int s = pts.get(pidx).x;
                    for (int j = pts.get(pidx).y; j <= up; j++) {
                        bx.update(j, -1);
                        by.update(j, s + 1);
                    }
                    pidx++;
                }

                ans[qs[i].idx] -= bx.query(y) * x + by.query(y);
            }
            for (long s : ans) out.println(s);


//        while (q-->0) {
//            int l = in.nextInt()-1, r = in.nextInt()-1;
//            int len = r - l + 1;
//            long ret = len * (len - 1) / 2 + len;
//
//            Point w;
//            MODE = 0;
//            w = pts.ceiling(new Point(l, 0));
//            if (w == null) {
//                out.println(ret);
//                continue;
//            }
//            System.out.println(w);
//
//            MODE = 1;
//            w = pts.floor(new Point(0, r));
//            if (w == null) {
//                out.println(ret);
//                continue;
//            }
//            System.out.println(w);
//
//
//            out.println(ret);
//        }
        }

        public void dfs(int node, int par) {
            vis[node] = true;
            p[node] = par;
            depth[node] = par == -1 ? 0 : (depth[par] + 1);
            for (int next : graph[node]) {
                if (next == par) continue;
                if (vis[next] && depth[next] < depth[node]) {
                    int c1 = next, c2 = next;
                    int t = node;
                    do {
                        c1 = Math.min(c1, t);
                        c2 = Math.max(c2, t);
                        t = p[t];
                    } while (t != next);
                    tt.add(new TaskC.Point(c1, c2));
                } else if (!vis[next]) {
                    dfs(next, node);
                }
            }
        }

        static class Query {
            public int l;
            public int r;
            public int idx;

            public Query(int l, int r, int idx) {
                this.l = l;
                this.r = r;
                this.idx = idx;
            }

        }

        static class Point implements Comparable<TaskC.Point> {
            public int x;
            public int y;
            public int id;

            public Point(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public Point(int x, int y, int id) {
                this.x = x;
                this.y = y;
                this.id = id;
            }


            public String toString() {
                return "Point{" +
                        "x=" + x +
                        ", y=" + y +
                        ", id=" + id +
                        '}';
            }

            public int compareTo(TaskC.Point other) {
                if (MODE == 0) return x - other.x;
                else return y - other.y;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class BITLong {
        private long[] tree;
        private int N;

        public BITLong(int N) {
            this.N = N;
            this.tree = new long[N + 3];
        }

        public long query(int K) {
            K += 2;
            long sum = 0;
            for (int i = K; i > 0; i -= (i & -i))
                sum += tree[i];
            return sum;
        }

        public void update(int K, long val) {
            K += 2;
            for (int i = K; i < tree.length; i += (i & -i))
                tree[i] += val;
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}