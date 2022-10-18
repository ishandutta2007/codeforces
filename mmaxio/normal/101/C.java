import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    boolean check(int x0, int y0, int x1, int y1) {
        if (x1 == 0 && y1 == 0) {
            return x0 == 0 && y0 == 0;
        }
        long det = (long)x1 * x1 + (long)y1 * y1;
        
        long v1 = (long)x1 * y0 - (long)y1 * x0;
        long v2 = (long)x0 * x1 + (long)y0 * y1;
        return v2 % det == 0 && v1 % det == 0;
    }

    void solve() throws IOException {
        int ax = nextInt();
        int ay = nextInt();
        int bx = nextInt();
        int by = nextInt();
        int cx = nextInt();
        int cy = nextInt();

        if (check(bx - ax, by - ay, cx, cy) || check(bx + ax, by + ay, cx, cy)
                || check(bx - ay, by + ax, cx, cy)
                || check(bx + ay, by - ax, cx, cy))
            out.print("YES");
        else
            out.print("NO");
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