import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        
        int[] d = new int[n];
        for (int i = 0; i < n; i++)
            d[i] = nextInt();
        
        if (n == 1) {
            out.println(d[0]);
            out.println(1);
            return;
        }
        
        if (n == 2) {
            out.println(Math.max(d[0], d[1]));
            out.println("1 2");
            return;
        }
        
        int[][] dp = new int[n + 1][n];
        
        for (int i = 0; i < n; i++)
            dp[n][i] = d[i];
        
        for (int i = 0; i < n - 1; i++)
            dp[n - 1][i] = Math.max(d[n - 1], d[i]);
        
        for (int i = n - 2; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                dp[i][j] = Math.max(d[i], d[i + 1]) + dp[i + 2][j];
                dp[i][j] = Math.min(dp[i][j], Math.max(d[j], d[i]) + dp[i + 2][i + 1]);
                dp[i][j] = Math.min(dp[i][j], Math.max(d[j], d[i + 1]) + dp[i + 2][i]);
            }
        }
        
        out.println(dp[1][0]);
        
        for (int z = 0, ci = 1, cj = 0; z < (n + 1) / 2; z++) {
            if (ci == n) {
                out.println(cj + 1);
                continue;
            }
            if (ci == n - 1) {
                out.println((ci + 1) + " " + (cj + 1));
                continue;
            }
            if (dp[ci][cj] == Math.max(d[ci], d[ci + 1]) + dp[ci + 2][cj]) {
                out.println((ci + 1) + " " + (ci + 2));
                ci += 2;
            } else if (dp[ci][cj] == Math.max(d[cj], d[ci]) + dp[ci + 2][ci + 1]) {
                out.println((cj + 1) + " " + (ci + 1));
                cj = ci + 1;
                ci += 2;
            } else if (dp[ci][cj] == Math.max(d[cj], d[ci + 1]) + dp[ci + 2][ci]) {
                out.println((cj + 1) + " " + (ci + 2));
                cj = ci;
                ci += 2;
            } else
                throw new AssertionError();
        }
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D().inp();
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