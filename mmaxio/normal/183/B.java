import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    int getBinocular(Point a, Point b, int n) {
        long A = b.y - a.y;
        long B = a.x - b.x;
        long C = A * a.x + B * a.y;
        if (A == 0)
            return -1;
        if (C % A != 0)
            return -1;
        long res = C / A;
        if (res >= 1 && res <= n)
            return (int)res;
        return -1;
    }
    
    boolean isOnLine(Point a, Point b, Point c) {
        long val = (long)(c.x - a.x) * (b.y - a.y) - (long)(c.y - a.y) * (b.x - a.x);
        return val == 0;
    }

    void solve() throws IOException {
        
        int n = nextInt();
        int m = nextInt();
        Point[] a = new Point[m];
        for (int i = 0; i < m; i++)
            a[i] = new Point(nextInt(), nextInt());
        
        HashMap<Integer, Integer> best = new HashMap<Integer, Integer>();
        
        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < m; j++) {
                int x;
                if ((x = getBinocular(a[i], a[j], n)) != -1) {
                    int now = 0;
                    for (int k = 0; k < m; k++)
                        if (k == i || k == j)
                            now++;
                        else if (isOnLine(a[i], a[j], a[k]))
                            now++;
                    Integer prev = best.get(x);
                    if (prev == null || now > prev) {
                        best.put(x, now);
                    }
                }
            }
        
        //System.err.println(best);
        
        long ans = n;
        for (Map.Entry<Integer, Integer> e : best.entrySet()) {
            ans--;
            ans += e.getValue();
        }
        
        out.println(ans);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().inp();
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