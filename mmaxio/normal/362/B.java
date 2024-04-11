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
        int[] a = new int[m];
        
        for (int i = 0; i < m; i++) {
            a[i] = nextInt();
        }
        
        Arrays.sort(a);
        
        if (m == 0) {
            out.println("YES");
            return;
        }
        
        if (a[0] == 1 || a[m - 1] == n) {
            out.println("NO");
            return;
        }
        
        for (int i = 0; i < m - 2; i++) {
            if (a[i + 1] == a[i] + 1 && a[i + 2] == a[i] + 2) {
                out.println("NO");
                return;
            }
        }
        
        out.println("YES");
    }

    B() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B();
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