import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final int MAX_ITERS = 100;
    final double EPS = 1e-7;   

    class Point {
        double x, y, z;

        public Point(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public Point(Point a, Point b, double c) {
            this.x = a.x * (1 - c) + b.x * c;
            this.y = a.y * (1 - c) + b.y * c;
            this.z = a.z * (1 - c) + b.z * c;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ", " + z + ")";
        }

    }

    double len(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)
                + (a.z - b.z) * (a.z - b.z));
    }

    boolean good(Point a, Point b, double startTime) {
        double l = 0;
        double r = 1;

        double len = len(a, b);

        double timeMe, timeBall;
        
        for (int it = 0; it < MAX_ITERS; it++) {
            double c = (l + r) * 0.5;
            Point mid = new Point(a, b, c);
            timeMe = len(start, mid) / vMy;
            timeBall = startTime + c * len / vBall;
            if (timeMe < timeBall)
                r = c;
            else
                l = c;
        }

        // System.err.println(l + " " + r);
        // System.err.println(a + " " + b);

        double best = (l + r) * 0.5;
        // System.err.println(best);
        Point p = new Point(a, b, best);
        timeBall = startTime + best * len / vBall;
        timeMe = len(start, p) / vMy;
        if (timeBall + EPS < timeMe)
            return false;
        out.println("YES");
        out.printf("%.9f\n", timeBall);
        out.printf("%.9f %.9f %.9f\n", p.x, p.y, p.z);
        return true;

    }

    int vMy, vBall;
    Point start;

    void solve() throws IOException {
        int n = nextInt();
        Point[] path = new Point[n + 1];
        for (int i = 0; i < n + 1; i++)
            path[i] = new Point(nextInt(), nextInt(), nextInt());

        vMy = nextInt();
        vBall = nextInt();

        start = new Point(nextInt(), nextInt(), nextInt());
        double curTime = 0;
        for (int i = 0; i < n; i++) {
            if (good(path[i], path[i + 1], curTime))
                return;
            else
                curTime += len(path[i], path[i + 1]) / vBall;
        }

        out.print("NO");
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