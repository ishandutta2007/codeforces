import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    int count(int x, int k) {
        int ans = 0;
        while (x > 0) {
            ans += x;
            x /= k;
        }
        return ans;
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        
        int l = 0;
        int r = n;
        
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            int val = count(mid, k);
            if (val >= n)
                r = mid;
            else
                l = mid;
        }
        out.println(r);
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