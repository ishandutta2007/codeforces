import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    static class Edge {
        int to, len;

        public Edge(int to, int len) {
            this.to = to;
            this.len = len;
        }
        
    }
    
    List<Edge>[] g;
    
    boolean[] vis;
    
    long dfs(int v) {
        vis[v] = true;
        long ret = 0;
        for (int i = 0; i < g[v].size(); i++) {
            Edge e = g[v].get(i);
            ret += e.len;
            if (!vis[e.to]) {
                ret += dfs(e.to);
            }
        }
        return ret;
    }
    
    static class Pair implements Comparable<Pair>{
        int v;
        long val;
        
        public Pair(int v, long val) {
            this.v = v;
            this.val = val;
        }

        @Override
        public int compareTo(Pair o) {
            return Long.compare(val, o.val);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int build = nextInt();
        int need = nextInt();
        
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>(0);
        }
        
        int edge1 = -1;
        int edge2 = -1;
        
        for (int i = 0; i < m; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            edge1 = v1;
            edge2 = v2;
            int len = nextInt();
            g[v1].add(new Edge(v2, len));
            g[v2].add(new Edge(v1, len));
        }
        
        

        List<Integer> roots = new ArrayList<>(0);
        List<Long> sum = new ArrayList<>(0);
        
        vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                roots.add(i);
                long cur = dfs(i);
                sum.add(cur / 2);
            }
        }
        
        if (roots.size() < need || roots.size() - need > build) {
            out.println("NO");
            return;
        }
        
        if (roots.size() == n && build > 0 && need == n) {
            out.println("NO");
            return;
        }
        
        if (n == 1 && build > 0) {
            out.println("NO");
            return;
        }
        
//      System.err.println(roots);
//      System.err.println(sum);
        
        out.println("YES");
        int conn = roots.size() - need;
        
        PriorityQueue<Pair> q = new PriorityQueue<>();
        for (int i = 0; i < roots.size(); i++) {
            q.add(new Pair(roots.get(i), sum.get(i)));
        }
        
        for (int i = 0; i < conn; i++) {
            Pair p1 = q.poll();
            Pair p2 = q.poll();
            long newVal = Math.min(p1.val + p2.val + 1, 1_000_000_000);
            out.println(p1.v + 1 + " " + (p2.v + 1));
            edge1 = p1.v;
            edge2 = p2.v;
            q.add(new Pair(p1.v, p1.val + p2.val + newVal));
        }
        
        for (int i = conn; i < build; i++) {
            out.println((edge1 + 1) + " " + (edge2 + 1));
        }
    }

    D() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D();
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