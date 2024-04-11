import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static class Edge {
        int to;
        Edge rev;
        boolean used;

        public Edge(int to) {
            this.to = to;
        }

    }

    List<Edge>[] g;

    boolean[] vis;

    List<Integer> ans;

    void markUsed(Edge e) {
        if (e.used || e.rev.used) {
            throw new AssertionError();
        }
        e.used = e.rev.used = true;
    }

    boolean dfs(int v, Edge p) {
        vis[v] = true;
        for (int i = 0; i < g[v].size(); i++) {
            Edge e = g[v].get(i);
            if (!vis[e.to]) {
                dfs(e.to, e);
            }
        }

        Edge noPair = null;

        for (int i = 0; i < g[v].size(); i++) {
            Edge e = g[v].get(i);
            if (e.rev == p) {
                continue;
            }
            if (!e.used) {
                if (noPair == null) {
                    noPair = e;
                } else {
                    ans.add(noPair.to);
                    ans.add(v);
                    ans.add(e.to);
                    markUsed(noPair);
                    markUsed(e);
                    noPair = null;
                }
            }
        }

        if (noPair != null) {
            if (p != null) {
                ans.add(noPair.to);
                ans.add(v);
                ans.add(p.rev.to);
                markUsed(noPair);
                markUsed(p);
            } else {
                return false;
            }
        }

        return true;

    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Edge>(0);
        }

        ans = new ArrayList<Integer>(3 * m / 2);

        for (int i = 0; i < m; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            Edge e1 = new Edge(v2);
            Edge e2 = new Edge(v1);
            e1.rev = e2;
            e2.rev = e1;
            g[v1].add(e1);
            g[v2].add(e2);
        }

        vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                boolean ret = dfs(i, null);
                if (!ret) {
                    out.println("No solution");
                    return;
                }
            }
        }

        for (int i = 0; i < ans.size(); i += 3) {
            out.println((ans.get(i) + 1) + " " + (ans.get(i + 1) + 1) + " "
                    + (ans.get(i + 2) + 1));
        }
    }

    C() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}