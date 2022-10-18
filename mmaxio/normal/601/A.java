import java.io.*;
import java.util.*;

public class A {

    static final int INF = Integer.MAX_VALUE / 3;
    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    int n;
    boolean[][] g;
    
    int[] bfs(int init, boolean edge) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        int[] d = new int[n];
        Arrays.fill(d, INF);
        d[init] = 0;
        q.add(init);
        while (!q.isEmpty()) {
            int v = q.poll();
            for (int u = 0; u < n; u++) {
                if (g[v][u] == edge && d[u] > d[v] + 1) {
                    d[u] = d[v] + 1;
                    q.add(u);
                }
            }
        }
        return d;
    }

    void solve() throws IOException {
        n = nextInt();
        g = new boolean[n][n];
        int m = nextInt();
        for (int i = 0; i < m; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            g[v1][v2] = g[v2][v1] = true;
        }
        
        int[] d1 = bfs(0, true);
        int[] d2 = bfs(0, false);
        
        int ret = Math.max(d1[n - 1], d2[n - 1]);
        out.println(ret == INF ? -1 : ret);
    }

    A() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A();
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