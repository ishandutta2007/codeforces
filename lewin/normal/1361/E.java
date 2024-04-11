import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;

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
        HJamesAndTheChase solver = new HJamesAndTheChase();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class HJamesAndTheChase {
        int n;
        int m;
        List<Integer>[] graph;
        int[] depth;
        int[] low;
        int[] vis;
        int[] backcount;
        int vidx;
        boolean[] anc;
        boolean[] ok;
        int[] st;

        boolean dfs(int node) {
            vis[node] = vidx;
            anc[node] = true;
            low[node] = depth[node];
            for (int next : graph[node]) {
                if (vis[next] == vidx) {
                    if (!anc[next]) return false;
                    low[node] = Math.min(low[node], depth[next]);
                } else {
                    depth[next] = depth[node] + 1;
                    if (!dfs(next)) return false;
                    low[node] = Math.min(low[node], low[next]);
                }
            }
            anc[node] = false;
            return true;
        }

        int dfs2(int node) {
            vis[node] = vidx;
            int c = 0;
            for (int next : graph[node]) {
                if (vis[next] == vidx) {
                    c++;
                    backcount[next]++;
                } else {
                    c += dfs2(next);
                }
            }
            c -= backcount[node];
            ok[node] = c <= 1;
            return c;
        }

        void dfs3(int node) {
            vis[node] = vidx;
            st[depth[node]] = node;
            ok[node] &= ok[st[low[node]]];
            for (int next : graph[node]) {
                if (vis[next] != vidx) {
                    dfs3(next);
                }
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            graph = LUtils.genArrayList(n);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(b);
            }
            low = new int[n];
            depth = new int[n];
            ok = new boolean[n];
            vis = new int[n];
            st = new int[n];
            anc = new boolean[n];
            backcount = new int[n];

            List<List<Integer>> scc = SCCKosaraju.scc(graph);
            List<Integer>[] dg = SCCKosaraju.sccGraph(graph, scc);
            int[] indeg = new int[n];
            for (int i = 0; i < dg.length; i++) {
                for (int x : dg[i]) {
                    indeg[x]++;
                }
            }
            for (int i = 1; i < dg.length; i++) {
                if (indeg[i] == 0) {
                    out.println(-1);
                    return;
                }
            }
            List<Integer> good = scc.get(0);
            Collections.shuffle(good);
            for (int itt = 0; itt < Math.min(good.size(), 40); itt++) {
                vidx++;
                Arrays.fill(anc, false);
                int k = good.get(itt);
                depth[k] = 0;
                if (dfs(k)) {
                    vidx++;
                    dfs2(k);
                    vidx++;
                    dfs3(k);
                    List<Integer> ans = new ArrayList<>();
                    for (int i : scc.get(0)) {
                        if (ok[i]) {
                            ans.add(i + 1);
                        }
                    }
                    Collections.sort(ans);
                    if (ans.size() * 5 >= n) {
                        boolean first = true;
                        for (int tk : ans) {
                            if (!first) out.print(" ");
                            first = false;
                            out.print(tk);
                        }
                        out.println();
                    } else {
                        out.println(-1);
                    }
                    return;
                }
            }
            out.println(-1);
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

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class SCCKosaraju {
        public static List<List<Integer>> scc(List<Integer>[] graph) {
            int n = graph.length;
            boolean[] used = new boolean[n];
            List<Integer> order = new ArrayList<>();
            for (int i = 0; i < n; i++)
                if (!used[i])
                    dfs(graph, used, order, i);

            List<Integer>[] reverseGraph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            for (int i = 0; i < n; i++)
                for (int j : graph[i])
                    reverseGraph[j].add(i);

            List<List<Integer>> components = new ArrayList<>();
            Arrays.fill(used, false);
            Collections.reverse(order);

            for (int u : order)
                if (!used[u]) {
                    List<Integer> component = new ArrayList<>();
                    dfs(reverseGraph, used, component, u);
                    components.add(component);
                }

            return components;
        }

        static void dfs(List<Integer>[] graph, boolean[] used, List<Integer> res, int u) {
            used[u] = true;
            for (int v : graph[u])
                if (!used[v])
                    dfs(graph, used, res, v);
            res.add(u);
        }

        public static List<Integer>[] sccGraph(List<Integer>[] graph, List<List<Integer>> components) {
            int[] comp = new int[graph.length];
            for (int i = 0; i < components.size(); i++)
                for (int u : components.get(i))
                    comp[u] = i;
            List<Integer>[] g = Stream.generate(ArrayList::new).limit(components.size()).toArray(List[]::new);
            Set<Long> edges = new HashSet<>();
            for (int u = 0; u < graph.length; u++)
                for (int v : graph[u])
                    if (comp[u] != comp[v] && edges.add(((long) comp[u] << 32) + comp[v]))
                        g[comp[u]].add(comp[v]);
            return g;
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}