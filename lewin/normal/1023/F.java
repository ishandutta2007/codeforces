import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.stream.Stream;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CellPhoneNetwork solver = new CellPhoneNetwork();
        solver.solve(1, in, out);
        out.close();
    }

    static class CellPhoneNetwork {
        List<CellPhoneNetwork.Edge>[] graph;
        int[] parent;
        int[] depth;
        boolean[] vis;
        boolean[] mine;
        int[] p;
        int[] highest;

        public void dfs(int node, int par) {
            vis[node] = true;
            parent[node] = par;
            depth[node] = par == -1 ? 0 : (depth[par] + 1);
            for (CellPhoneNetwork.Edge next : graph[node]) {
                if (next.to == par) continue;
                mine[next.to] = next.mine;
                dfs(next.to, node);
            }
        }

        public int find(int x) {
            return x == p[x] ? x : (p[x] = find(p[x]));
        }

        public boolean unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                if (Math.random() < 0.5)
                    p[a] = b;
                else
                    p[b] = a;

                int high = depth[highest[a]] < depth[highest[b]] ? highest[a] : highest[b];
                highest[a] = highest[b] = high;
                return true;
            }
            return false;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt(), m = in.nextInt();

            graph = LUtils.genArrayList(n);
            int[] dd = DisjointSets.createSets(n);
            for (int i = 0; i < k; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(new CellPhoneNetwork.Edge(b, true));
                graph[b].add(new CellPhoneNetwork.Edge(a, true));
                DisjointSets.unite(dd, a, b);
            }
            int[] qq = DisjointSets.createSets(n);
            int[] a = new int[m], b = new int[m], w = new int[m];
            for (int i = 0; i < m; i++) {
                a[i] = in.nextInt() - 1;
                b[i] = in.nextInt() - 1;
                w[i] = in.nextInt();
                DisjointSets.unite(qq, a[i], b[i]);
                if (DisjointSets.unite(dd, a[i], b[i])) {
                    graph[a[i]].add(new CellPhoneNetwork.Edge(b[i], false));
                    graph[b[i]].add(new CellPhoneNetwork.Edge(a[i], false));
                }
            }

            parent = new int[n];
            depth = new int[n];
            vis = new boolean[n];
            mine = new boolean[n];
            dfs(0, -1);

            p = new int[n];
            highest = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                highest[i] = i;
            }

            long ans = 0;
            int used = 0;
            for (int i = 0; i < m; i++) {
                int xa = highest[find(a[i])];
                int xb = highest[find(b[i])];

                while (xa != xb) {
                    if (depth[xa] < depth[xb]) {
                        int t = xa;
                        xa = xb;
                        xb = t;
                    }
                    if (mine[xa]) {
                        used++;
                        ans += w[i];
                    }
                    int pa = parent[xa];
                    unite(xa, pa);
                    xa = highest[find(pa)];
                }
            }
            out.println(used == k ? ans : -1);
        }

        static class Edge {
            public int to;
            public boolean mine;

            public Edge(int to, boolean mine) {
                this.to = to;
                this.mine = mine;
            }

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

    static class DisjointSets {
        public static int[] createSets(int size) {
            int[] p = new int[size];
            for (int i = 0; i < size; i++)
                p[i] = i;
            return p;
        }

        public static int root(int[] p, int x) {
            return x == p[x] ? x : (p[x] = root(p, p[x]));
        }

        public static boolean unite(int[] p, int a, int b) {
            a = root(p, a);
            b = root(p, b);
            if (a != b) {
                if (Math.random() < 0.5)
                    p[a] = b;
                else
                    p[b] = a;
                return true;
            }
            return false;
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

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
        }

    }
}