import java.io.*;
import java.util.*;

public class D_new {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int[] fact, invFact, inv;
    static final int N = 2000;
    static final int P = 1000000007;

    int C(int n, int k) {
        if (n < 0 || k < 0 || k > n) {
            return 0;
        }
        return (int) ((long) fact[n] * invFact[k] % P * invFact[n - k] % P);
    }

    int[][] cntDiff = new int[47][1001];
    int[][] memo = new int[1001][1001];
    {
        for (int i = 0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
    }

    int solve(int n, int k) {
        if (memo[n][k] != -1) {
            return memo[n][k];
        }

        int free = n - k;
        if (free < k * (k - 1) / 2) {
            return memo[n][k] = 0;
        }
        
        // System.err.println(free);

        int ret = 0;
        for (int i = 0; i <= free; i++) {
            ret += (int) ((long) C(i + k, i) * cntDiff[k][free - i] % P);
            if (ret >= P) {
                ret -= P;
            }
        }

        ret = (int) ((long) ret * fact[k] % P);

        return memo[n][k] = ret;

    }

    D_new() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);

        fact = new int[N + 1];
        invFact = new int[N + 1];
        inv = new int[N + 1];

        fact[0] = invFact[0] = 1;
        inv[1] = invFact[1] = fact[1] = 1;
        for (int x = 2; x <= N; x++) {
            inv[x] = P - (int) ((long) (P / x) * inv[P % x] % P);
            fact[x] = (int) ((long) fact[x - 1] * x % P);
            invFact[x] = (int) ((long) invFact[x - 1] * inv[x] % P);
        }

        Arrays.fill(cntDiff[1], 1);

        int[][] dp = new int[1001][1001]; // sum last
        int[][] next = new int[1001][1001];
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j <= 1000; j++) {
                dp[i][j] = i <= j ? 1 : 0;
            }
        }

        for (int j = 2; j < cntDiff.length; j++) {
            for (int i = 0; i <= 1000; i++) {
                Arrays.fill(next[i], 0);
            }
            for (int prevSum = 0; prevSum <= 1000; prevSum++)
                for (int maxLast = 0; maxLast <= 1000; maxLast++) {
                    if (dp[prevSum][maxLast] != 0) {
                        if (prevSum + maxLast + 1 <= 1000
                                && maxLast + 1 <= 1000) {
                            next[prevSum + maxLast + 1][maxLast + 1] += dp[prevSum][maxLast];
                            if (next[prevSum + maxLast + 1][maxLast + 1] >= P) {
                                next[prevSum + maxLast + 1][maxLast + 1] -= P;
                            }
                        }
                    }
                }

            for (int sum = 0; sum <= 1000; sum++)
                for (int last = 0; last <= 1000; last++) {
                    cntDiff[j][sum] += next[sum][last];
                    if (cntDiff[j][sum] >= P) {
                        cntDiff[j][sum] -= P;
                    }
                }

            for (int sum = 0; sum <= 1000; sum++)
                for (int last = 1; last <= 1000; last++) {
                    next[sum][last] += next[sum][last - 1];
                    if (next[sum][last] >= P) {
                        next[sum][last] -= P;
                    }
                }
            int[][] tmp = dp;
            dp = next;
            next = tmp;
        }

        int t = nextInt();
        while (t-- > 0) {
            int n = nextInt();
            int k = nextInt();
            out.println(solve(n, k));
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D_new();
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