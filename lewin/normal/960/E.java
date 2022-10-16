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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public static final int mod = 1000000007;
        int[] size;
        boolean[] removed;
        int numeven;
        int numodd;
        long ans;
        List<Integer>[] graph;
        long[] vals;
        int n;
        Pair<Integer, Integer>[] tot;
        HashMap<Pair<Integer, Integer>, Pair<Integer, Integer>> mp;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            vals = in.readLongArray(n);
            for (int i = 0; i < n; i++) {
                vals[i] = (vals[i] + mod) % mod;
            }
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
                graph[b].add(a);
            }

            ans = 0;
            size = new int[n];
            removed = new boolean[n];
            mp = new HashMap<>();
            tot = new Pair[n];
            dfs1(find_center(0));
            ans = ans * 2 % mod;
            for (int i = 0; i < n; i++) {
                ans += vals[i];
                if (ans >= mod) ans -= mod;
            }
            out.println(ans);
        }

        void dfs1(int node) {
            removed[node] = true;
            long base = 0;
            int ne = 0, no = 1;
            for (int x : graph[node]) {
                if (removed[x]) {
                    numeven = tot[x].v;
                    numodd = tot[x].u;
                    Pair<Integer, Integer> t = mp.get(new Pair<>(x, node));
                    numeven -= t.v;
                    numodd -= t.u;
                } else {
                    numeven = 0;
                    numodd = 0;
                    dfs2(node, x, 0);
                    mp.put(new Pair<>(node, x), new Pair<>(numeven, numodd));
                }

                base -= 1L * ne * numeven % mod;
                if (base < 0) base += mod;
                base += 1L * no * numodd % mod;
                if (base >= mod) base -= mod;

                ne += numeven;
                no += numodd;
            }

            tot[node] = new Pair<>(ne, no);
            ans += 1L * base * vals[node] % mod;
            ans %= mod;

            for (int x : graph[node]) {
                if (removed[x]) continue;
                dfs1(find_center(x));
            }
        }

        void dfs2(int par, int cur, int depth) {
            if (depth % 2 == 0) {
                numeven++;
            } else {
                numodd++;
            }
            size[cur] = 1;
            for (int next : graph[cur]) {
                if (next == par) continue;
                if (removed[next]) {
                    if (depth % 2 == 1) {
                        numeven += tot[next].v;
                        numodd += tot[next].u;
                        Pair<Integer, Integer> t = mp.get(new Pair<>(next, cur));
                        numeven -= t.v;
                        numodd -= t.u;
                    } else {
                        numeven += tot[next].u;
                        numodd += tot[next].v;
                        Pair<Integer, Integer> t = mp.get(new Pair<>(next, cur));
                        numeven -= t.u;
                        numodd -= t.v;
                    }
                    continue;
                }
                dfs2(cur, next, depth + 1);
                size[cur] += size[next];
            }
        }

        int find_center(int node) {
            int par = -1;
            dfs2(-1, node, 0);
            int cap = size[node] >> 1;
            while (true) {
                boolean found = false;
                for (int next : graph[node]) {
                    if (next != par && !removed[next] && size[next] > cap) {
                        found = true;
                        par = node;
                        node = next;
                        break;
                    }
                }
                if (!found) return node;
            }
        }

    }

    static class LUtils {
        public static <E> List<E>[] genArrayList(int size) {
            return Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
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

        public long[] readLongArray(int tokens) {
            long[] ret = new long[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextLong();
            }
            return ret;
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
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

        public String toString() {
            return String.format("[Pair = (%s, %s)", u.toString(), v.toString());
        }

    }
}