import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int INF = Integer.MAX_VALUE / 3;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int low = nextInt();
        int high = nextInt();
        char[][] f = new char[n][];
        for (int i = 0; i < n; i++)
            f[i] = nextToken().toCharArray();

        int[][] cost = new int[2][m];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cost[f[j][i] == '.' ? 0 : 1][i]++;
        
        //System.err.println(Arrays.deepToString(cost));

        int[][] dp = new int[2][high];
        for (int i = 0; i < 2; i++) {
            Arrays.fill(dp[i], INF);
            dp[i][0] = cost[i][0];
        }
        
        int[] stop = new int[2];

        for (int i = 1; i < m; i++) {
            
            for (int j = 0; j < 2; j++) {
                stop[j] = INF;
                for (int w = low - 1; w <= high - 1; w++)
                    stop[j] = Math.min(stop[j], dp[j][w]);
            }

            for (int j = 0; j < 2; j++) {
                for (int w = high - 1; w > 0; w--) {
                    dp[j][w] = dp[j][w - 1] == INF ? INF : dp[j][w - 1] + cost[j][i]; 
                }
                dp[j][0] = (stop[1 - j] == INF) ? INF : stop[1 - j] + cost[j][i];
            }
        }
        
        int ans = INF;
        for (int j = 0; j < 2; j++)
            for (int w = low - 1; w <= high - 1; w++)
                ans = Math.min(ans, dp[j][w]);
        
        out.println(ans);
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