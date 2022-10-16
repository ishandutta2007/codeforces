import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public List<Integer>[] graph;
        public int[] par;
        public int[] diam;
        public long[] eee;
        public List<Integer>[] vals;
        public List<Long>[] psums;
        public int[] up;
        public int[] down;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), q = in.nextInt();
            graph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            par = DisjointSets.createSets(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                DisjointSets.unite(par, a, b);
                graph[a].add(b);
                graph[b].add(a);
            }
            int[] ff = getFarthest();
            diam = new int[n];
            vals = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            psums = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            for (int i = 0; i < n; i++) {
                int ee = DisjointSets.root(par, i);
                diam[ee] = Math.max(diam[ee], ff[i]);
                vals[ee].add(ff[i]);
            }
            eee = new long[n];
            for (int i = 0; i < n; i++) {
                if (vals[i].size() > 0) {
                    Collections.sort(vals[i]);
                    long csum = 0;
                    psums[i].add(csum);
                    for (int x : vals[i]) {
                        psums[i].add(csum += x);
                    }
                    eee[i] = csum;
                }
            }
            HashMap<Pair<Integer, Integer>, Double> mp = new HashMap<>();
            while (q-- > 0) {
                int a = DisjointSets.root(par, in.nextInt() - 1);
                int b = DisjointSets.root(par, in.nextInt() - 1);
                if (a == b) {
                    out.println(-1);
                    continue;
                }
                if (a > b) {
                    int t = a;
                    a = b;
                    b = t;
                }
                Pair<Integer, Integer> key = new Pair<>(a, b);
                Double ww = mp.get(key);
                if (ww != null) {
                    out.printf("%.10f\n", ww);
                    continue;
                }

                double ans = solve(a, b);
                mp.put(key, ans);
                out.printf("%.10f\n", ans);
            }
        }

        public double solve(int a, int b) {
            if (vals[a].size() > vals[b].size()) {
                int t = a;
                a = b;
                b = t;
            }

            int base = Math.max(diam[a], diam[b]);
            long s = 0;
            for (int x : vals[a]) {
                int need = base - x;
                int idx = find(vals[b], need);
                s += 1L * idx * base + 1L * (vals[b].size() - idx) * (1 + x) + (eee[b] - psums[b].get(idx));
            }

            return s / (double) vals[a].size() / (double) vals[b].size();
        }

        public int find(List<Integer> x, int val) {
            int lo = 0, hi = x.size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (x.get(mid) < val) lo = mid + 1;
                else hi = mid;
            }
            return lo;
        }

        public int[] getFarthest() {
            int n = graph.length;
            down = new int[n];
            up = new int[n];
            for (int root = 0; root < n; root++) {
                if (DisjointSets.root(par, root) == root) {
                    dfs(root, -1);
                    dfs2(root, -1, 0);
                }
            }
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = Math.max(up[i], down[i]);
            }
            return ret;
        }

        public void dfs(int node, int par) {
            for (int next : graph[node]) {
                if (next == par) continue;
                dfs(next, node);
                down[node] = Math.max(down[node], down[next] + 1);
            }
        }

        public void dfs2(int node, int par, int frompar) {
            up[node] = frompar;
            int mx1 = 0, id1 = -1, mx2 = 0;
            for (int next : graph[node]) {
                if (next == par) continue;
                if (down[next] + 1 > mx1) {
                    mx2 = mx1;
                    mx1 = down[next] + 1;
                    id1 = next;
                } else if (down[next] + 1 > mx2) {
                    mx2 = down[next] + 1;
                }
            }

            for (int next : graph[node]) {
                if (next == par) continue;
                dfs2(next, node, Math.max(up[node], next == id1 ? mx2 : mx1) + 1);
            }
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
        private byte[] buf = new byte[1024];
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements Comparable<Pair<U, V>> {
        public final U u;
        public final V v;

        public Pair(U u, V v) {
            this.u = u;
            this.v = v;
        }

        public int hashCode() {
            return (u == null ? 0 : u.hashCode() * 31) + (v == null ? 0 : v.hashCode());
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<U, V> p = (Pair<U, V>) o;
            return (u == null ? p.u == null : u.equals(p.u)) && (v == null ? p.v == null : v.equals(p.v));
        }

        public int compareTo(Pair<U, V> b) {
            int cmpU = u.compareTo(b.u);
            return cmpU != 0 ? cmpU : v.compareTo(b.v);
        }

    }
}