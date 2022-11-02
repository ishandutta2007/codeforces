import java.util.Arrays;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Collection;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Queue;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    ArrayList<Pair> factorize(int n) {
        ArrayList<Pair> res = new ArrayList<>();
        int cur = n;
        for (int i = 2; i * i <= n; i++) {
            if (cur % i == 0) {
                int p = 0;
                while (cur % i == 0) {
                    p++;
                    cur /= i;
                }
                res.add(new Pair(i, p));
            }
        }
        if (cur > 1)
            res.add(new Pair(cur, 1));
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        boolean[][] g = new boolean[n][n];
        for (int i = 0; i < m; i++) {
            int c = in.nextInt();
            int b = in.nextInt();
            c--;
            b--;
            g[c][b] = g[b][c] = true;
        }
        int cntL = 0;
        int cntR = 0;
        ArrayList<Pair>[] factors = new ArrayList[n];
        ArrayList<Integer>[] ids = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            factors[i] = factorize(a[i]);
            ids[i] = new ArrayList<>();
            for (int j = 0; j < factors[i].size(); j++)
                if (i % 2 == 0)
                    ids[i].add(cntL++);
                else
                    ids[i].add(cntR++);
        }
        if (cntL == 0 || cntR == 0) {
            out.println(0);
            return;
        }
        int sink = 1 + cntL + cntR;
        int source = 0;
        MaxFlow maxFlow = new MaxFlow(2 + cntL + cntR, source, sink);
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                for (int j = 0; j < factors[i].size(); j++)
                    maxFlow.addEdge(source, ids[i].get(j) + 1, factors[i].get(j).second);
            else
                for (int j = 0; j < factors[i].size(); j++)
                    maxFlow.addEdge(ids[i].get(j) + cntL + 1, sink, factors[i].get(j).second);
        for (int i = 0; i < n; i += 2)
            for (int j = 1; j < n; j += 2)
                if (g[i][j])
                    for (int p1 = 0; p1 < factors[i].size(); p1++)
                        for (int p2 = 0; p2 < factors[j].size(); p2++)
                            if (factors[i].get(p1).first == factors[j].get(p2).first)
                                maxFlow.addEdge(ids[i].get(p1) + 1, ids[j].get(p2) + cntL + 1, maxFlow.INF);
        out.println(maxFlow.getFlow());
    }

    class MaxFlow {
        final int INF = (int)1e6;

        class Edge {
            int from;
            int to;
            int flow;
            int cap;

            Edge(int from, int to, int cap) {
                this.from = from;
                this.to = to;
                this.cap = cap;
                this.flow = 0;
            }

            boolean isOpen() {
                return cap > flow;
            }

            int getLeft() {
                return cap - flow;
            }
        }

        ArrayList<Edge> e = new ArrayList<>();
        int[] dist;
        int[] parEdge;
        int[] first;
        ArrayList<Integer>[] g;
        int source;
        int sink;

        MaxFlow(int size, int source, int sink) {
            this.source = source;
            this.sink = sink;
            dist = new int[size];
            parEdge = new int[size];
            first = new int[size];
            g = new ArrayList[size];
            for (int i = 0; i < size; i++)
                g[i] = new ArrayList<>();
        }

        void addEdge(int from, int to, int cap) {
            //System.err.println(from + " " + to + " " + cap);
            int size = e.size();
            e.add(new Edge(from, to, cap));
            e.add(new Edge(to, from, 0));
            g[from].add(size);
            g[to].add(size + 1);
        }

        private boolean bfs() {
            Arrays.fill(dist, INF);
            dist[source] = 0;
            Queue<Integer> q = new ArrayDeque<>();
            q.add(source);
            while (!q.isEmpty()) {
                int v = q.poll();
                for (int j : g[v]) {
                    Edge curr = e.get(j);
                    int to = curr.to;
                    if (curr.isOpen() && dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        q.add(to);
                    }
                }
            }
            return dist[sink] != INF;
        }

        private boolean dfs(int v, int pe) {
            parEdge[v] = pe;
            if (v == sink)
                return true;
            if (dist[v] >= dist[sink])
                return false;
            for (; first[v] < g[v].size(); first[v]++) {
                Edge curr = e.get(g[v].get(first[v]));
                if (curr.isOpen() && dist[curr.to] == dist[v] + 1 && dfs(curr.to, g[v].get(first[v])))
                    return true;
            }
            return false;
        }

        int pushFlow() {
            int add = INF;
            int v = sink;
            while (v != source) {
                Edge curr = e.get(parEdge[v]);
                add = Math.min(add, curr.getLeft());
                v = curr.from;
            }
            v = sink;
            while  (v != source) {
                int i = parEdge[v];
                e.get(i).flow += add;
                e.get(i ^ 1).flow -= add;
                v = e.get(i).from;
            }
            return add;
        }

        int getFlow() {
            int flow = 0;
            while (bfs()) {
                Arrays.fill(first, 0);
                while (dfs(source, -1))
                    flow += pushFlow();
            }
            return flow;
        }
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                // ignore
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}