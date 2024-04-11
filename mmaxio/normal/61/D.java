import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Edge {
        int to, cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        
    }
    
    ArrayList<Edge>[] g;
    
    int dfs(int v, int par) {
        int res = 0;
        for (Edge e : g[v])
            if (e.to != par) {
                res = Math.max(res, e.cost + dfs(e.to, v));
            }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        g = new ArrayList[n];
        long ans = 0;
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<Edge>();
        for (int i = 0; i < n - 1; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            int cost = nextInt();
            g[v1].add(new Edge(v2, cost));
            g[v2].add(new Edge(v1, cost));
            ans += 2 * cost;
        }
        
        ans -= dfs(0, -1);
        
        out.print(ans);
        
        
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