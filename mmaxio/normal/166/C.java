import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int x = nextInt();
        int less = 0;
        int eq = 0;
        
        for (int i = 0; i < n; i++) {
            int tmp = nextInt();
            if (tmp < x)
                less++;
            if (tmp == x)
                eq++;
        }
        
        int ans = 0;
        while (true) {
            int mid = (n - 1) >> 1;
            if (less <= mid) {
                if (mid - less - eq + 1 <= ans) {
                    out.println(ans);
                    return;
                }
            }
            ans++;
            n++;
        }
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