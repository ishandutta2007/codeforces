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
        public List<Long>[] graph;
        public int[] parl;
        public int INF = 1 << 29;
        public int n;
        public int m;
        int len;
        int[][] up;
        int[] tin;
        int[] tout;
        int time;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            graph = Stream.generate(ArrayList::new).limit(n).toArray(List[]::new);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                graph[a].add(1L * b * n + i);
                graph[b].add(1L * a * n + i);
            }
            init(graph, 0);
            int nnodes = n * len + m + 2;
            List<MaxFlowDinic.Edge>[] gg = Stream.generate(ArrayList::new).limit(nnodes).toArray(List[]::new);
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                int r = lca(a, b);
                for (int j = len - 1; j >= 0; j--) {
                    if (!isParent(up[j][a], r)) {
                        MaxFlowDinic.addEdge(gg, i, m + a * len + j, 1);
                        a = up[j][a];
                    }
                    if (!isParent(up[j][b], r)) {
                        MaxFlowDinic.addEdge(gg, i, m + b * len + j, 1);
                        b = up[j][b];
                    }
                }
                if (a != r) {
                    MaxFlowDinic.addEdge(gg, i, m + a * len + 0, 1);
                }
                if (b != r) {
                    MaxFlowDinic.addEdge(gg, i, m + b * len + 0, 1);
                }
                MaxFlowDinic.addEdge(gg, nnodes - 1, i, 1);
            }

            for (int i = 1; i < n; i++) {
                MaxFlowDinic.addEdge(gg, m + i * len + 0, nnodes - 2, 1);
                for (int j = 1; j < len; j++) {
                    MaxFlowDinic.addEdge(gg, m + i * len + j, m + i * len + j - 1, INF);
                    if (up[j - 1][i] != 0)
                        MaxFlowDinic.addEdge(gg, m + i * len + j, m + up[j - 1][i] * len + j - 1, INF);
                }
            }

            Set<Integer> mc = MaxFlowDinic.minCut(gg, nnodes - 1, nnodes - 2);
            HashSet<Integer> a1 = new HashSet<>();
            for (int i = 0; i < m; i++) a1.add(i + 1);
            ArrayList<Integer> a2 = new ArrayList<>();
            for (int x : mc) {
                if (x == nnodes - 1 || x == nnodes - 2) continue;
                if (x < m) {
                    a1.remove(x + 1);
                } else {
                    int d = (x - m);
                    if (d % len != 0) continue;
                    d /= len;
                    a2.add(parl[d] + 1);
                }
            }

            out.println(a1.size() + a2.size());
            out.print(a1.size());
            for (int x : a1) out.print(" " + x);
            out.println();
            out.print(a2.size());
            for (int x : a2) out.print(" " + x);
            out.println();
        }

        public void init(List<Long>[] tree, int root) {
            int n = tree.length;
            len = 1;
            while ((1 << len) <= n) ++len;
            up = new int[len][n];
            tin = new int[n];
            tout = new int[n];
            parl = new int[n];
            dfs(tree, root, root);
        }

        void dfs(List<Long>[] tree, int u, int p) {
            tin[u] = time++;
            up[0][u] = p;
            for (int i = 1; i < len; i++)
                up[i][u] = up[i - 1][up[i - 1][u]];
            for (long d : tree[u]) {
                int v = (int) (d / n);
                if (v != p) {
                    parl[v] = (int) (d % n);
                    dfs(tree, v, u);
                }
            }
            tout[u] = time++;
        }

        boolean isParent(int parent, int child) {
            return tin[parent] <= tin[child] && tout[child] <= tout[parent];
        }

        public int lca(int a, int b) {
            if (isParent(a, b))
                return a;
            if (isParent(b, a))
                return b;
            for (int i = len - 1; i >= 0; i--)
                if (!isParent(up[i][a], b))
                    a = up[i][a];
            return up[0][a];
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

    static class MaxFlowDinic {
        public static void addEdge(List<MaxFlowDinic.Edge>[] graph, int s, int t, int cap) {
            graph[s].add(new MaxFlowDinic.Edge(t, graph[t].size(), cap));
            graph[t].add(new MaxFlowDinic.Edge(s, graph[s].size() - 1, 0));
        }

        static boolean dinicBfs(List<MaxFlowDinic.Edge>[] graph, int src, int dest, int[] dist) {
            Arrays.fill(dist, -1);
            dist[src] = 0;
            int[] Q = new int[graph.length];
            int sizeQ = 0;
            Q[sizeQ++] = src;
            for (int i = 0; i < sizeQ; i++) {
                int u = Q[i];
                for (MaxFlowDinic.Edge e : graph[u]) {
                    if (dist[e.t] < 0 && e.f < e.cap) {
                        dist[e.t] = dist[u] + 1;
                        Q[sizeQ++] = e.t;
                    }
                }
            }
            return dist[dest] >= 0;
        }

        static int dinicDfs(List<MaxFlowDinic.Edge>[] graph, int[] ptr, int[] dist, int dest, int u, int f) {
            if (u == dest)
                return f;
            for (; ptr[u] < graph[u].size(); ++ptr[u]) {
                MaxFlowDinic.Edge e = graph[u].get(ptr[u]);
                if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
                    int df = dinicDfs(graph, ptr, dist, dest, e.t, Math.min(f, e.cap - e.f));
                    if (df > 0) {
                        e.f += df;
                        graph[e.t].get(e.rev).f -= df;
                        return df;
                    }
                }
            }
            return 0;
        }

        public static int maxFlow(List<MaxFlowDinic.Edge>[] graph, int src, int dest) {
            int flow = 0;
            int[] dist = new int[graph.length];
            while (dinicBfs(graph, src, dest, dist)) {
                int[] ptr = new int[graph.length];
                while (true) {
                    int df = dinicDfs(graph, ptr, dist, dest, src, Integer.MAX_VALUE);
                    if (df == 0)
                        break;
                    flow += df;
                }
            }
            return flow;
        }

        public static Set<Integer> minCut(List<MaxFlowDinic.Edge>[] graph, int src, int dest) {
            maxFlow(graph, src, dest);
            Set<Integer> ret = new HashSet<>();
            int n = graph.length;
            int[] queue = new int[n];
            int front = 0, back = 0;
            queue[back++] = src;
            ret.add(src);
            while (front < back) {
                int node = queue[front++];
                for (MaxFlowDinic.Edge e : graph[node]) {
                    if (!ret.contains(e.t) && e.f < e.cap) {
                        ret.add(e.t);
                        queue[back++] = e.t;
                    }
                }
            }
            return ret;
        }

        public static class Edge {
            int t;
            int rev;
            int cap;
            int f;

            public Edge(int t, int rev, int cap) {
                this.t = t;
                this.rev = rev;
                this.cap = cap;
            }

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
}