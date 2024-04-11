import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final int INF = Integer.MAX_VALUE / 2;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        if (n > m) {
            int tmp = n;
            n = m;
            m = tmp;
        }
        // n < m !!!!
        // n rows m columns

        if (n == 1) {
            out.print(m - (m + 2) / 3);
            return;
        }

        int[][] dp = new int[n * m + 1][1 << (2 * n)];
        for (int i = 0; i < dp.length; i++)
            Arrays.fill(dp[i], INF);

        dp[0][0] = 0;
        for (int i = 0; i < dp.length - 1; i++) {
            int maxNewMask = (1 << Math.min(2 * n, n * m - i)) - 1;
            for (int mask = 0; mask < dp[i].length; mask++)
                if (dp[i][mask] != INF) {
                    //System.err.println(i + " " + mask + " " + dp[i][mask]);
                    if ((mask & 1) == 1) // already covered, skip
                        dp[i + 1][mask >> 1] = Math.min(dp[i + 1][mask >> 1],
                                dp[i][mask]);
                    // place on this tile
                    int newMask = mask >> 1;
                    if (i % n != n - 1)
                        newMask |= 1;
                    newMask |= 1 << (n - 1);
                    newMask &= maxNewMask;
                    dp[i + 1][newMask] = Math.min(dp[i + 1][newMask],
                            dp[i][mask] + 1);

                    if (i % n != n - 1) {// place on next tile
                        newMask = mask >> 1;
                        newMask |= 1;
                        if (i % n != n - 2)
                            newMask |= 2;
                        newMask |= (1 << n);
                        newMask &= maxNewMask;
                        dp[i + 1][newMask] = Math.min(dp[i + 1][newMask],
                                dp[i][mask] + 1);
                    }

                    // place on lower tile
                    if (i + n < n * m) {
                        newMask = mask >> 1;
                        newMask |= 1 << (n - 1);
                        if (i % n != 0)
                            newMask |= 1 << (n - 2);
                        if (i % n != n - 1)
                            newMask |= 1 << n;
                        newMask |= 1 << (2 * n - 1);
                        newMask &= maxNewMask;
                        dp[i + 1][newMask] = Math.min(dp[i + 1][newMask],
                                dp[i][mask] + 1);
                    }
                }
            
            
        }
        
        out.print(n * m - dp[n * m][0]);

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