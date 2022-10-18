import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    int get(int n, int x, int y) {
        if (y == 0)
            return x;
        if (x == n)
            return n + y;
        if (y == n)
            return 2 * n + (n - x);
        if (x == 0)
            return 3 * n + (n - y);
        return 42;
    }

    void solve() throws IOException {
        int n = nextInt();
        int x1 = nextInt();
        int y1 = nextInt();
        int x2 = nextInt();
        int y2 = nextInt();
        
        int p1 = get(n, x1, y1);
        int p2 = get(n, x2, y2);
        
        int res = Math.abs(p2 - p1);
        res = Math.min(res, 4 * n - res);
        
        out.print(res);
        
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().inp();
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