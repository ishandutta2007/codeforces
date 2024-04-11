import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int we = nextInt() - 1;
        
        int[] sz = new int[m];
        for (int i = 0; i < m; i++) 
            sz[i] = nextInt();
        
        sz[we]--; n--;
        
        int total = 0;
        for (int i = 0; i < m; i++)
            total += sz[i];
        
        int exc = total - sz[we];
        
        if (total < n) {
            out.println(-1);
            return;
        }
        
        if (exc < n) {
            out.println(1);
            return;
        }
        
        double res = 1;
        for (int i = 0; i < n; i++)
            res *= 1.0 * (exc - i) / (total - i);
        
        out.printf(Locale.US, "%.9f", 1 - res);
        
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