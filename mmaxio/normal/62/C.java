import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    Random rnd = new Random();

    class Point implements Comparable<Point> {
        double x, y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            if (Math.abs(x - o.x) >= EPS)
                return x < o.x ? -1 : 1;
            return Math.abs(y - o.y) < EPS ? 0 : y < o.y ? -1 : 1;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }

    }

    boolean cross;

    final double EPS = 1e-5;

    boolean inside(Point a, Point b, Point c) {
        double x1 = b.x - a.x;
        double y1 = b.y - a.y;
        double x2 = c.x - a.x;
        double y2 = c.y - a.y;

        return x1 * x2 + y1 * y2 < EPS;
    }

    Point crossSegm(Point a, Point b, Point c, Point d) {
//      System.err.println(a + " - " + b);
//      System.err.println(c + " - " + d);
//      System.err.println("----------------");
        
        double A1 = b.y - a.y;
        double B1 = a.x - b.x;
        double C1 = -a.x * A1 - a.y * B1;

        double A2 = d.y - c.y;
        double B2 = c.x - d.x;
        double C2 = -c.x * A2 - c.y * B2;

        double det = A1 * B2 - A2 * B1;
        cross = false;
        if (Math.abs(det) < EPS)
            return null;

        Point p = new Point(-(C1 * B2 - C2 * B1) / det, -(A1 * C2 - A2 * C1)
                / det);
        
//      System.err.println(p);
//      System.err.println("-----------------");

        cross = inside(p, a, b) && inside(p, c, d);

        return p;

    }

    Point[][] ls;
    int n;

    boolean good(Point p) {
        //System.err.println(p);
        for (int i = 0; i < n; i++) {
            boolean hasNeg = false;
            boolean hasPos = false;
            boolean onSide = false;
            for (int j = 0; j < 3; j++) {
                Point p1 = ls[i][j];
                Point p2 = ls[i][(j + 1) % 3];
                double A = p2.y - p1.y;
                double B = p1.x - p2.x;
                double C = - A * p1.x - B * p1.y;
                double expr = A * p.x + B * p.y + C;
                if (Math.abs(expr) < EPS) 
                    onSide = true;
                else if (expr < 0)
                    hasNeg = true;
                else
                    hasPos = true;
            }
            if (onSide)
                continue;
            if (!hasNeg || !hasPos)
                return false;
        }
        return true;
    }
    
    double len(Point a, Point b) {
        //System.err.println(a + " - " + b);
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    
    Point mid(Point a, Point b) {
        return new Point((a.x + b.x) * 0.5, (a.y + b.y) * 0.5);
    }

    void solve() throws IOException {
        n = nextInt();
        ls = new Point[n][3];

        double ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                ls[i][j] = new Point(nextDouble(), nextDouble());

        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++) {
                ArrayList<Point> tmp = new ArrayList<Point>();
                tmp.add(ls[i][j]);
                tmp.add(ls[i][(j + 1) % 3]);
                for (int i1 = 0; i1 < n; i1++)
                    for (int j1 = 0; j1 < 3; j1++) {
                        cross = false;
                        Point p = crossSegm(ls[i][j], ls[i][(j + 1) % 3],
                                ls[i1][j1], ls[i1][(j1 + 1) % 3]);
                        if (cross)
                            tmp.add(p);
                    }
                Collections.sort(tmp);
//              System.err.println(tmp);
                for (int jj = 0; jj < tmp.size() - 1; jj++) {
                    Point a = tmp.get(jj);
                    Point b = tmp.get(jj + 1);
                    if (good(mid(a, b)))
                        ans += len(tmp.get(jj), tmp.get(jj + 1));
                }
            }
        
        out.printf("%.10f", ans);
    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
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