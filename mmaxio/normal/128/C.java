import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final int MOD = 1000000007;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();

        if (Math.min(n, m) < 2 * k + 1) {
            out.print(0);
            return;
        }

        int[][] dp = new int[k + 1][Math.max(n, m) + 1];
        int[][] pref = new int[k + 1][Math.max(n, m) + 1];
        Arrays.fill(dp[0], 1);
        dp[0][0] = 0;
        for (int i = 1; i < dp[0].length; i++)
            pref[0][i] = pref[0][i - 1] + dp[0][i];
        for (int i = 1; i < dp.length; i++) {
            for (int j = 2 * i + 1; j < dp[i].length; j++) {
                dp[i][j] = dp[i][j - 1] + pref[i - 1][j - 2];
                if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;  
                pref[i][j] = pref[i][j - 1] + dp[i][j];
                if (pref[i][j] >= MOD)
                    pref[i][j] -= MOD;

            }
//          System.err.println(Arrays.toString(dp[i]));
//          System.err.println(Arrays.toString(pref[i]));
        }

        out.print((long) dp[k][n] * dp[k][m] % MOD);
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