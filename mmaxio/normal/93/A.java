import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int a = nextInt() - 1;
        int b = nextInt() - 1;
        
        
        int r1 = a / m;
        int c1 = a - r1 * m;
        
        int r2 = b / m;
        int c2 = b - r2 * m;
        
        if (a == 0 && b == n - 1) {
            out.print(1);
            return;
        }
        
        if (r1 == r2) {
            out.print(1);
            return;
        }
        
        if (c1 == 0 && c2 == m - 1) {
            out.print(1);
            return;
        }
        
        if (c1 == 0 && b == n - 1) {
            out.print(1);
            return;
        }
        
        if (c1 == 0 || c2 == m - 1) {
            out.print(2);
            return;
        }
        
        if (c1 == c2 + 1) {
            out.print(2);
            return;
        }
        
        if (r2 == r1 + 1) {
            out.print(2);
            return;
        }
        
        if (b == n - 1) {
            out.print(2);
            return;
        }
        
        out.print(3);
        
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