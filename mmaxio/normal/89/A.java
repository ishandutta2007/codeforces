import java.io.*;
import java.util.*;

public class A {
    
    final int INF = Integer.MAX_VALUE / 2;

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        
        if (n % 2 == 0) {
            out.print(0);
            return;
        }
        
        int totMax = INF;
        
        for (int i = 0; i < n; i += 2)
            totMax = Math.min(totMax, a[i]);
        
        int steal = (n + 1) / 2;
        
        m /= steal;
        
        long total = (long)k * m;
        
        
        if (total < (long)totMax)
            out.print(total);
        else
            out.print(totMax);
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