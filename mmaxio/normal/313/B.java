import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        String s = nextToken();
        int n = s.length();
        int[] a = new int[n];
        
        for (int i = 0; i < n - 1; i++) {
            a[i + 1] = a[i];
            if (s.charAt(i) == s.charAt(i + 1))
                a[i + 1]++;
        }
        
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int l = nextInt() - 1;
            int r = nextInt() - 1;
            out.println(a[r] - a[l]);
        }
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