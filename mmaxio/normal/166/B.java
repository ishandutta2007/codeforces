import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    class Point implements Comparable<Point>{
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        public Point(Point a, Point b) {
            this(b.x - a.x, b.y - a.y);
        }

        @Override
        public int compareTo(Point o) {
            long val = (long)x * o.y - (long)y * o.x;
            return (val == 0) ? 0 : (val > 0 ? -1 : 1);
        }
        
    }
    
    Point[] a;
    int N;
    
    boolean inside(Point p, Point a, Point b) {
        // a < p < b already
        Point AP = new Point(a, p);
        Point AB = new Point(a, b);
        if (AB.compareTo(AP) >= 0)
            return false;
        Point BP = new Point(b, p);
        Point BA = new Point(b, a);
        if (BP.compareTo(BA) >= 0)
            return false;
        return true;
    }
    
    boolean inside(Point p) {
        if (p.x < 0 || (p.x == 0 && p.y <= 0))
            return false;
        if (p.compareTo(a[0]) <= 0 || p.compareTo(a[N - 1]) >= 0)
            return false;
        int i = Arrays.binarySearch(a, p);
        if (i < 0) {
            i = -i - 2;
            return inside(p, a[i], a[i + 1]);
        } else
            return (Math.abs(p.x) < Math.abs(a[i].x)) || (Math.abs(p.y) < Math.abs(a[i].y)); 
    }

    void solve() throws IOException {
        int n = nextInt();
        int x0 = Integer.MAX_VALUE;
        int y0 = Integer.MAX_VALUE;
        int st = -1;
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
            y[i] = nextInt();
            if (x[i] < x0 || (x[i] == x0 && y[i] < y0)) {
                x0 = x[i];
                y0 = y[i];
                st = i;
            }
        }
        
        N = n - 1;
        a = new Point[n - 1];
        int ptr = 0;
        for (int i = st - 1; i >= 0; i--)
            a[ptr++] = new Point(x[i] - x0, y[i] - y0);
        for (int i = n - 1; i >= st + 1; i--)
            a[ptr++] = new Point(x[i] - x0, y[i] - y0);
        
        int m = nextInt();
        for (int i = 0; i < m; i++) {
            Point p = new Point(nextInt() - x0, nextInt() - y0);
            if (!inside(p)) {
                out.println("NO");
                return;
            }
        }
        
        out.println("YES");
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