import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Edge implements Comparable<Edge> {
        int v1, v2, cost, id;

        public Edge(int v1, int v2, int cost, int id) {
            super();
            this.v1 = v1;
            this.v2 = v2;
            this.cost = cost;
            this.id = id;
        }

        @Override
        public int compareTo(Edge o) {
            return cost - o.cost;
        }

    }

    int[] p;
    int[] depth;
    int[] up;

    int[] active;
    int activeVer = 0;

    ArrayList<Edge>[] g1;
    ArrayList<Integer> curActive;

    int[] ans;

    int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }

    void dfs(int v, int d, Edge pr) {
        active[v] = 0;
        depth[v] = d;
        up[v] = d;

        for (Edge e : g1[v])
            if (pr == null || e.id != pr.id) {
                int to = get(e.v1) == v ? get(e.v2) : get(e.v1);
                if (active[to] == 0)
                    up[v] = Math.min(up[v], depth[to]);
                else {
                    dfs(to, d + 1, e);
                    up[v] = Math.min(up[v], up[to]);
                }
            }

        if (up[v] == d && pr != null)
            ans[pr.id] = 1;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        g1 = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g1[i] = new ArrayList<Edge>();
        depth = new int[n];
        up = new int[n];
        curActive = new ArrayList<Integer>();
        active = new int[n];

        Edge[] g = new Edge[m];
        for (int i = 0; i < m; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            int cost = nextInt();
            g[i] = new Edge(v1, v2, cost, i);
        }

        Arrays.sort(g);

        ans = new int[m];

        p = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = i;

        for (int st = 0; st < m;) {
            activeVer++;
            curActive.clear();
            int en = st;
            while (en < m && g[st].cost == g[en].cost)
                en++;
            for (int i = st; i < en; i++) {
                int v1 = get(g[i].v1);
                int v2 = get(g[i].v2);
                if (v1 == v2)
                    ans[g[i].id] = -1;
                else {
                    if (active[v1] != activeVer) {
                        curActive.add(v1);
                        active[v1] = activeVer;
                        g1[v1].clear();
                    }
                    g1[v1].add(g[i]);
                    if (active[v2] != activeVer) {
                        curActive.add(v2);
                        active[v2] = activeVer;
                        g1[v2].clear();
                    }
                    g1[v2].add(g[i]);
                }
            }

            for (int v : curActive)
                if (active[v] == activeVer)
                    dfs(v, 0, null);

            for (int i = st; i < en; i++) {
                int v1 = get(g[i].v1);
                int v2 = get(g[i].v2);
                if (v1 != v2) {
                    if (((v1 + v2) & 1) == 1)
                        p[v1] = v2;
                    else
                        p[v2] = v1;
                }
            }

            st = en;
        }

        for (int i = 0; i < m; i++) {
            if (ans[i] == -1)
                out.println("none");
            else if (ans[i] == 0)
                out.println("at least one");
            else
                out.println("any");
        }
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }

    String nextString() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken("\n");
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