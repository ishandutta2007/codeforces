import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    static final int MOD = 1000000007;

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        char[] t = nextToken().toCharArray();
        
        int n = t.length;
        int[] dp = new int[n + 1];
        int ans = 0;
        
        for (char c : s) {
            int[] next = new int[n + 1];
            for (int i = 0; i < n; i++) {
                int cur = (t[i] == c) ? (dp[i] + 1) : 0;
                next[i + 1] = next[i] + cur;
                if (next[i + 1] >= MOD)
                    next[i + 1] -= MOD;
            }
            dp = next;
            ans += dp[n];
            if (ans >= MOD)
                ans -= MOD;
        }
        
        out.println(ans);
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