import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    long go(int l, int r, int big) {
        if (l > r)
            return 0;
        long res = (long) l * (big - l);
        res = Math.max(res, (long) r * (big - r));
        
        int tmp = big / 2;
        if (l <= tmp && tmp <= r)
            res = Math.max(res, (long) tmp * (big - tmp));
        
        tmp++;
        if (l <= tmp && tmp <= r)
            res = Math.max(res, (long) tmp * (big - tmp));
        
        return res;     
    }

    void solve() throws IOException {
        int l = nextInt();
        int r = nextInt();
        long ans = 0;
        if (r == 1000000000) {
            ans = 8999999999L * 1000000000;
            r--;
            if (l == 1000000000)
                l--;
        }
        for (int left = 1, right = 9; left <= 100000000; left *= 10, right *= 10, right += 9) {
            int leftB = Math.max(left, l);
            int rightB = Math.min(right, r);
            
            ans = Math.max(ans, go(leftB, rightB, right));
        }
        
        out.print(ans);
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