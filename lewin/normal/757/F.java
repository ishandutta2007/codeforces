import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public ArrayList<Dijkstra.Edge>[] graph;
        public ArrayList<Integer>[] dag;
        public ArrayList<Integer>[] inc;
        public ArrayList<Integer>[] child;
        public int[] size;
        public int[] depth;
        public int[][] anc;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), s = in.nextInt() - 1;
            graph = new ArrayList[n];
            for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1, c = in.nextInt();
                graph[a].add(new Dijkstra.Edge(b, c));
                graph[b].add(new Dijkstra.Edge(a, c));
            }
            long[] dist = new long[n];
            Dijkstra.dijkstra(graph, dist, s);
            dag = new ArrayList[n];
            inc = new ArrayList[n];
            int[] indeg = new int[n];
            for (int i = 0; i < n; i++) dag[i] = new ArrayList<>();
            for (int i = 0; i < n; i++) inc[i] = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                for (Dijkstra.Edge e : graph[i]) {
                    if (dist[i] + e.weight == dist[e.to]) {
                        dag[i].add(e.to);
                        inc[e.to].add(i);
                        indeg[e.to]++;
                    }
                }
            }
            child = new ArrayList[n];
            for (int i = 0; i < n; i++) child[i] = new ArrayList<>();
            int front = 0, back = 0;
            int[] queue = new int[n];
            queue[back++] = s;
            anc = new int[20][n];
            for (int[] x : anc) Arrays.fill(x, -1);
            depth = new int[n];
            while (front < back) {
                int cur = queue[front++];
                if (cur == s) {
                    depth[s] = 0;
                    anc[0][s] = -1;
                } else {
                    int par = inc[cur].get(0);
                    for (int i = 1; i < inc[cur].size(); i++) {
                        int d = inc[cur].get(i);
                        par = lca(par, d);
                    }
                    depth[cur] = depth[par] + 1;
                    anc[0][cur] = par;
                    for (int i = 1; i < 20; i++) {
                        if (anc[i - 1][cur] == -1) {
                            break;
                        } else {
                            anc[i][cur] = anc[i - 1][anc[i - 1][cur]];
                        }
                    }
                    child[par].add(cur);
                }
                for (int next : dag[cur]) if (--indeg[next] == 0) queue[back++] = next;
            }

            size = new int[n];
            dfs(s);
            int ret = 0;
            for (int i = 0; i < n; i++) {
                if (i != s)
                    ret = Math.max(ret, size[i]);
            }
            out.println(ret);
        }

        public int dfs(int node) {
            size[node] = 1;
            for (int next : child[node]) {
                size[node] += dfs(next);
            }
            return size[node];
        }

        public int lca(int a, int b) {
            if (depth[a] < depth[b]) {
                a ^= b;
                b ^= a;
                a ^= b;
            }

            int diff = depth[a] - depth[b];
            for (int i = 0; (1 << i) <= diff; i++)
                if ((diff & (1 << i)) != 0)
                    a = anc[i][a];

            if (a == b)
                return a;

            int log = 0;
            while (1 << (log + 1) <= depth[a])
                log++;

            for (int i = log; i >= 0; i--)
                if (anc[i][a] != anc[i][b]) {
                    a = anc[i][a];
                    b = anc[i][b];
                }

            return anc[0][a];
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

        public void println(int i) {
            writer.println(i);
        }

    }

    static class Dijkstra {
        public static long INF = 1L << 60;

        public static void dijkstra(ArrayList<Dijkstra.Edge>[] graph, long[] dist, int start) {
            int N = dist.length;
            Arrays.fill(dist, INF);
            PriorityQueue<Dijkstra.Edge> pq = new PriorityQueue<Dijkstra.Edge>();
            pq.add(new Dijkstra.Edge(start, dist[start] = 0));

            while (pq.size() > 0) {
                int node = pq.peek().to;
                long weight = pq.peek().weight;
                pq.poll();
                if (dist[node] != weight) continue;

                for (Dijkstra.Edge e : graph[node]) {
                    if (dist[e.to] > dist[node] + e.weight)
                        pq.add(new Dijkstra.Edge(e.to, dist[e.to] = dist[node] + e.weight));
                }
            }
        }

        public static class Edge implements Comparable<Dijkstra.Edge> {
            public int to;
            public long weight;

            public Edge(int to, long weight) {
                this.to = to;
                this.weight = weight;
            }

            public int compareTo(Dijkstra.Edge other) {
                return Long.compare(weight, other.weight);
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}