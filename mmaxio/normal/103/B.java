import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    int fnd(int v, int[] p) {
        return (v == p[v]) ? v : (p[v] = fnd(p[v], p));
    }
    
    boolean uni(int v1, int v2, int[] p) {
        v1 = fnd(v1, p);
        v2 = fnd(v2, p);
        if (v1 != v2) {
            p[v1] = v2;
            return true;
        }
        return false;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        if (n < 3 || n != m) {
            out.println("NO");
            return;
        }
        
        int[] p = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = i;
        
        int cnt = n;
        
        for (int i = 0; i < m; i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            if (uni(v1, v2, p))
                cnt--;
        }
        
        out.println(cnt == 1 ? "FHTAGN!" : "NO");
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