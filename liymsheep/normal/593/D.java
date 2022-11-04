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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private long[] weight;
        private int[] parent;
        private Edge[] first;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            first = new Edge[n];
            parent = new int[n];
            weight = new long[n];
            Tree tree = new Tree(n);
            int[] us, vs;
            us = new int[n - 1];
            vs = new int[n - 1];
            for (int i = 0; i < n - 1; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                long w = in.nextLong();
                new Edge(u, v, w);
                new Edge(v, u, w);
                tree.insert(u, v, 1);

                us[i] = u;
                vs[i] = v;
            }

            tree.construct(0);
            dfs(0, -1);
            DisjointSet set = new DisjointSet(n);
            while (m-- != 0) {
                if (in.nextInt() == 1) {
                    int ai = in.nextInt() - 1;
                    int bi = in.nextInt() - 1;
                    long value = in.nextLong();
                    int lca = set.get(tree.lca(ai, bi));

                    int current = set.get(ai);
                    while (value > 0 && current != set.get(lca)) {
                        if (weight[current] == 1) {
                            set.union(current, parent[current]);
                        }
                        if (weight[current] > 1) value /= weight[current];
                        current = set.get(parent[current]);
                    }
                    current = set.get(bi);
                    while (value > 0 && current != set.get(lca)) {
                        if (weight[current] == 1) {
                            set.union(current, parent[current]);
                        }
                        if (weight[current] > 1) value /= weight[current];
                        current = set.get(parent[current]);
                    }
                    out.println(value);
                } else {
                    int p = in.nextInt() - 1;
                    long c = in.nextLong();
                    int u = us[p], v = vs[p];
                    if (parent[v] == u) {
                        int t = u;
                        u = v;
                        v = t;
                    }
                    weight[u] = c;
                }
            }
        }

        private void dfs(int x, int fa) {
            parent[x] = fa;
            for (Edge e = first[x]; e != null; e = e.next) {
                if (e.to != fa) {
                    weight[e.to] = e.cost;
                    dfs(e.to, x);
                }
            }
        }

        static class DisjointSet {
            int[] par;

            DisjointSet(int size) {
                par = new int[size];
                //     delta = new int[size];
                for (int i = 0; i < par.length; ++i) {
                    par[i] = i;
                }
            }

            int get(int x) {
                if (par[x] == x) {
                    return x;
                }
                par[x] = get(par[x]);
                //    delta[x] = (delta[oldPar] + delta[x]) % 3;
                return par[x];
            }

            void union(int y, int x) {
                int py = get(y);// yDelta = delta[y];
                //delta[py] = ((-yDelta + yx) % 3 + 3) % 3;
                par[py] = get(x);
            }

        }

        class Edge {
            int to;
            long cost;
            Edge next;

            Edge(int from, int to, long cost) {
                this.to = to;
                this.cost = cost;
                this.next = first[from];
                first[from] = this;
            }

        }

        static class Tree {
            final int MAXD;
            Edge[] first;
            int[][] father;
            int[] depth;
            long[] length;

            Tree(int n) {
                first = new Edge[n];
                MAXD = 20;
                father = new int[n][MAXD];
                depth = new int[n];
                length = new long[n];
            }

            void insert(int u, int v, int w) {
                new Edge(u, v, w);
                new Edge(v, u, w);
            }

            void construct(int root) {
                dfs(root, -1, 0, 0);
            }

            void dfs(int u, int fa, int nowDepth, long sumLength) {

                length[u] = sumLength;
                depth[u] = nowDepth;

                father[u][0] = fa;
                for (int i = 1; i < MAXD; ++i) {
                    father[u][i] = -1;
                    if (father[u][i - 1] != -1) {
                        father[u][i] = father[father[u][i - 1]][i - 1];
                    }
                }

                for (Edge e = first[u]; e != null; e = e.next) {
                    if (e.to != fa) {
                        dfs(e.to, u, nowDepth + 1, sumLength + e.w);
                    }
                }
            }

            int lca(int u, int v) {

                if (depth[u] > depth[v]) {
                    int t = u;
                    u = v;
                    v = t;
                }

                for (int i = MAXD - 1; i >= 0; --i) {
                    if (father[v][i] != -1 && depth[father[v][i]] >= depth[u]) {
                        v = father[v][i];
                    }
                }

                if (u == v) {
                    return u;
                }

                for (int i = MAXD - 1; i >= 0; --i) {
                    if (father[u][i] != father[v][i]) {
                        u = father[u][i];
                        v = father[v][i];
                    }
                }

                return father[u][0];
            }

            class Edge {
                int to;
                int w;
                Edge next;

                public Edge(int from, int to, int w) {
                    this.to = to;
                    this.w = w;
                    this.next = first[from];
                    first[from] = this;
                }

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