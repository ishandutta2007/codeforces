import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Pair implements Comparable<Pair> {
        int x, y;

        public Pair(int x, int y) {
            super();
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            if (x == o.x)
                return y - o.y;
            return x - o.x;
        }

    }
    
    class Edge {
        int to, cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        
    }
    
    void dfs(int v, int par, int c) {
        parent[v] = par;
        cap[v] = c;
        for (Edge e : g[v]) if (e.to != par)
            dfs(e.to, v, e.cost);   
    }
    
    int[] parent;
    int[] cap;
    
    ArrayList<Edge>[] g;

    void solve() throws IOException {
        int n = nextInt();
        Pair[] pr = new Pair[n];
        for (int i = 0; i < n; i++)
            pr[i] = new Pair(nextInt(), i);
        
        Arrays.sort(pr);
        
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Edge>();
        
        for (int i = 0; i < n - 1; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            int c = nextInt();
            g[v1].add(new Edge(v2, c));
            g[v2].add(new Edge(v1, c));
        }
        
        parent = new int[n];
        cap = new int[n];
        
        dfs(0, -1, 0);
        int[][] occup = new int[n][n];
        
        int[] ans = new int[n];
        
        for (int i = 0; i < n; i++) {
            int v = pr[i].y; int vv = v;
            int res = 0;
            while (v != 0) {
                while (occup[v][res] == cap[v])
                    res++;
                occup[v][res]++;
                v = parent[v];
                res++;
            }
            ans[vv] = res;
        }
        
        for (int i : ans)
            out.print(i + " ");
        
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().inp();
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