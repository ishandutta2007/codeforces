import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Point {
        int x, y, len;

        public Point(int x, int y) {
            super();
            this.x = x;
            this.y = y;
            this.len = x * x + y * y;
        }

        public Point(Point a, Point b) {
            this(b.x - a.x, b.y - a.y);
        }

        public int cross(Point p) {
            return x * p.x + y * p.y;
        }

    }
    
    boolean isSquareNoOrder(Point[] p) {
        return isSquare(new Point[]{p[0], p[1], p[2], p[3]}) ||
        isSquare(new Point[]{p[0], p[1], p[3], p[2]}) ||
        isSquare(new Point[]{p[0], p[2], p[1], p[3]});
    }
    
    boolean isRectangleNoOrder(Point[] p) {
        return isRectangle(new Point[]{p[0], p[1], p[2], p[3]}) ||
        isRectangle(new Point[]{p[0], p[1], p[3], p[2]}) ||
        isRectangle(new Point[]{p[0], p[2], p[1], p[3]});
    }

    boolean isSquare(Point[] p) {
        Point[] v = new Point[4];
        for (int i = 0; i < 4; i++)
            v[i] = new Point(p[i], p[(i + 1) % 4]);

        boolean res = true;

        for (int i = 0; i < 4; i++) {
            if (v[i].cross(v[(i + 1) % 4]) != 0)
                res = false;
            if (v[i].len != v[0].len)
                res = false;
            if (v[i].len == 0)
                res = false;
        }
        
        return res;

    }

    boolean isRectangle(Point[] p) {
        Point[] v = new Point[4];
        for (int i = 0; i < 4; i++)
            v[i] = new Point(p[i], p[(i + 1) % 4]);

        boolean res = true;

        for (int i = 0; i < 4; i++) {
            if (v[i].cross(v[(i + 1) % 4]) != 0)
                res = false;
            if (v[i].len == 0)
                res = false;
        }

        return res;
    }

    void solve() throws IOException {
        Point[] p = new Point[8];
        for (int i = 0; i < p.length; i++)
            p[i] = new Point(nextInt(), nextInt());

        for (int mask = 0; mask < (1 << 8); mask++)
            if (Integer.bitCount(mask) == 4) {
                Point[] sq = new Point[4];
                Point[] rect = new Point[4];
                int cntSq = 0;
                int cntRect = 0;

                for (int i = 0; i < 8; i++)
                    if (((mask >> i) & 1) == 1)
                        sq[cntSq++] = p[i];
                    else
                        rect[cntRect++] = p[i];

                if (isSquareNoOrder(sq) && isRectangleNoOrder(rect)) {
                    out.println("YES");
                    for (int i = 0; i < 8; i++)
                        if (((mask >> i) & 1) == 1)
                            out.print((i + 1) + " ");
                    out.println();
                    for (int i = 0; i < 8; i++)
                        if (((mask >> i) & 1) == 0)
                            out.print((i + 1) + " ");
                    return;
                }
            }

        out.print("NO");

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