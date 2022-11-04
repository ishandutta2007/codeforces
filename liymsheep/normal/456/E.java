import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author hellis
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n, m, q;
        n = in.nextInt();
        m = in.nextInt();
        q = in.nextInt();
        par = new int[n];
        for (int i = 0; i < n; ++i)
            par[i] = i;
        firstEdge = new Edge[n];
        for (int i = 0; i < m; ++i) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            new Edge(u, v);
            new Edge(v, u);
            merge(u, v);
        }

        vis = new boolean[n];
        diameter = new int[n];
        distance = new int[n];
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int length = getDiameter(i);
                diameter[getRoot(i)] = length;
            }
        }

        for (int i = 0; i < q; ++i) {
            int type = in.nextInt();
            if (type == 1) {
                int x = in.nextInt() - 1;
                out.println(diameter[getRoot(x)]);
            } else {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                u = getRoot(u);
                v = getRoot(v);
                if (u != v) {
                    int d1 = diameter[u];
                    int d2 = diameter[v];
                    int d3 = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
                    d3 = Math.max(d3, Math.max(d1, d2));
                    par[u] = v;
                    diameter[v] = d3;
                }
            }
        }
    }

    private void dfs(int u, List<Integer> list) {
        list.add(u);
        vis[u] = true;
        for (Edge e = firstEdge[u]; e != null; e = e.nextEdge) {
            if (vis[e.to]) continue;
            dfs(e.to, list);
        }
    }

    private int[] distance;

    private int[] bfs(int u, List<Integer> nodes) {
        for (Integer i : nodes) {
            vis[i] = false;
        }

        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(u);
        int far = u;
        distance[u] = 0;
        while (!queue.isEmpty()) {
            int x = queue.poll();
            vis[x] = true;
            if (distance[x] > distance[far]) {
                far = x;
            }
            for (Edge e = firstEdge[x]; e != null; e = e.nextEdge) {
                if (!vis[e.to]) {
                    distance[e.to] = distance[x] + 1;
                    queue.add(e.to);
                }
            }
        }

        return new int[] {distance[far], far};
    }

    private int getDiameter(int u) {
        List<Integer> comp = new ArrayList<Integer>();
        dfs(u, comp);
        int[] firstRound = bfs(u, comp);
        int[] secondRound = bfs(firstRound[1], comp);
        return secondRound[0];
    }

    private boolean[] vis;
    private int[] diameter;

    private Edge[] firstEdge;

    class Edge {
        Edge nextEdge;
        int to;

        Edge(int from, int to) {
            this.to = to;
            nextEdge = firstEdge[from];
            firstEdge[from] = this;
        }
    }

    private int[] par;

    int getRoot(int u) {
        return par[u] == u ? u : (par[u] = getRoot(par[u]));
    }

    void merge(int u, int v) {
        par[getRoot(u)] = getRoot(v);
    }
}

class InputReader {
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

}