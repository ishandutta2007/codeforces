import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static class Point {
        int x;
        long y;
        int ind;

        public Point(int x, long y, int ind) {
            this.x = x;
            this.y = y;
            this.ind = ind;
        }
    }

    List<Integer>[] g;
    int time;
    int[] tIn, tOut;

    static final int LOG = 17;

    void dfs(int v) {
        tIn[v] = time++;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            dfs(to);
        }
        tOut[v] = time++;
    }

    boolean isAnc(int v1, int v2) {
        return tIn[v1] <= tIn[v2] && tOut[v2] <= tOut[v1];
    }
    
    int[][] up;

    void solve() throws IOException {
        int n = nextInt();
        Point[] ps = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            long y = nextLong();
            ps[i] = new Point(x, y, i);
        }

        int[] next = new int[n];
        next[n - 1] = n - 1;

        List<Point> s = new ArrayList<>();
        s.add(ps[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            Point p = ps[i];
            while (s.size() > 1
                    && see(p, s.get(s.size() - 1), s.get(s.size() - 2))) {
                s.remove(s.size() - 1);
            }
            next[i] = s.get(s.size() - 1).ind;
            s.add(p);
        }
        
        // System.err.println(Arrays.toString(next));

        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>(0);
        }

        for (int i = 0; i <= n - 2; i++) {
            g[next[i]].add(i);
        }

        tIn = new int[n];
        tOut = new int[n];

        dfs(n - 1);

        up = new int[n][LOG];
        for (int i = 0; i < n; i++) {
            up[i][0] = next[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        int q = nextInt();
        while (q-- > 0) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            out.println(lca(v1, v2) + 1);
        }
    }
    
    int lca(int v1, int v2) {
        if (isAnc(v1, v2)) {
            return v1;
        }
        if (isAnc(v2, v1)) {
            return v2;
        }
        for (int j = LOG - 1; j >= 0; j--) {
            int to = up[v1][j];
            if (!isAnc(to, v2)) {
                v1 = to;
            }
        }
        
        return up[v1][0];
    }

    boolean see(Point a, Point b, Point c) {
        long x1 = b.x - a.x;
        long y1 = b.y - a.y;
        long x2 = c.x - a.x;
        long y2 = c.y - a.y;
//      System.err.println(x1 + " " + y1 + " " + x2 + " " + y2);
//      System.err.println(x1 * y2 - x2 * y1 < 0);
        return x1 * y2 - x2 * y1 > 0;
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