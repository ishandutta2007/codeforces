import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.Collection;
import java.io.InputStream;

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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    final int INF = 2000;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n; i++)
            b[i] = in.nextInt();
        int source = 2 * n;
        int sink = 2 * n + 1;
        MaximumFlowGraph g = new MaximumFlowGraph(2 * n + 2, source, sink);
        for (int i = 0; i < m; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            g.addEdge(2 * u + 1, 2 * v, INF);
            g.addEdge(2 * v + 1, 2 * u, INF);
        }
        int[][] ans = new int[n][n];
        int diff = 0;
        for (int i = 0; i < n; i++)
            g.addEdge(2 * i, 2 * i + 1, a[i]);
        for (int i = 0; i < n; i++) {
            int d = Math.abs(a[i] - b[i]);
            diff += d;
            if (a[i] <= b[i]) {
                g.addEdge(source, 2 * i + 1, d);
            } else {
                g.addEdge(2 * i + 1, sink, d);
            }
        }
        long flow = g.getFlow();
        if (2 * flow != diff) {
            out.println("NO");
            return;
        }
        for (int i = 0; i < n; i++)
            ans[i][i] = a[i];
        for (MaximumFlowGraph.Edge e : g.e) {
            if (e.from < 2 * n && e.to < 2 * n && e.flow > 0 && e.from / 2 != e.to / 2) {
                ans[e.to / 2][e.from / 2] = (int) e.flow;
            }
        }
        out.println("YES");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    ans[i][i] -= ans[i][j];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                out.print(ans[i][j] + " ");
            out.println();
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

class MaximumFlowGraph {
    final long INF = (long) 1e13;

    public class Edge {
        public int from;
        public int to;
        public long flow;
        public long cap;

        Edge(int from, int to, long cap) {
            this.from = from;
            this.to = to;
            this.cap = cap;
            this.flow = 0;
        }

        boolean isOpen() {
            return cap > flow;
        }

        long getLeft() {
            return cap - flow;
        }
    }

    public ArrayList<Edge> e = new ArrayList<>();
    long[] dist;
    int[] parEdge;
    int[] first;
    ArrayList<Integer>[] g;
    int source;
    int sink;

    public MaximumFlowGraph(int size, int source, int sink) {
        this.source = source;
        this.sink = sink;
        dist = new long[size];
        parEdge = new int[size];
        first = new int[size];
        g = new ArrayList[size];
        for (int i = 0; i < size; i++)
            g[i] = new ArrayList<>();
    }

    public void addEdge(int from, int to, long cap) {
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

    long pushFlow() {
        long add = INF;
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

    public long getFlow() {
        long flow = 0;
        while (bfs()) {
            Arrays.fill(first, 0);
            while (dfs(source, -1))
                flow += pushFlow();
        }
        return flow;
    }
}