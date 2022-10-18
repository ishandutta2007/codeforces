import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final int MOD = 1000000007;
    final int MAXN = 1000;

    int[] fact, revFact;

    int pow(int a, int b) {
        if (b == 0)
            return 1;
        else if ((b & 1) == 1)
            return (int) ((long) a * pow(a, b - 1) % MOD);
        else {
            int tmp = pow(a, b >> 1);
            return (int) ((long) tmp * tmp % MOD);
        }
    }

    int c(int n, int k) {
        return (int) ((long) fact[n] * revFact[k] % MOD * revFact[n - k] % MOD);
    }

    void solve() throws IOException {

        int n = nextInt();// number of rows
        int m = nextInt();// number of columns
        int k = nextInt();

        long start = System.currentTimeMillis();

        int[] calc = new int[Math.min(n, k) + 1];
        fact = new int[k + 1];
        revFact = new int[k + 1];

        fact[0] = 1;
        for (int i = 1; i <= k; i++)
            fact[i] = (int) ((long) i * fact[i - 1] % MOD);

        for (int i = 0; i <= k; i++)
            revFact[i] = pow(fact[i], MOD - 2);

        // number of ways to color column in i different colors
        // if colors are FIXED
        calc[1] = 1;
        for (int i = 2; i < calc.length; i++) {
            calc[i] = pow(i, n);
            for (int j = 1; j < i; j++) {
                calc[i] -= (long) c(i, j) * calc[j] % MOD;
                if (calc[i] < 0)
                    calc[i] += MOD;
            }
        }

        // System.err.println(Arrays.toString(calc));

        int ans = 0;

        if (m == 1) {
            for (int i = 1; i < calc.length; i++) {
                ans += (long) c(k, i) * calc[i] % MOD;
                if (ans >= MOD)
                    ans -= MOD;
            }
            out.print(ans);
            return;
        }

        if (m == 2) {
            for (int i = 1; i < calc.length; i++) {
                ans += (long) c(k, i) * calc[i] % MOD * c(k, i) % MOD * calc[i]
                        % MOD;
                if (ans >= MOD)
                    ans -= MOD;
            }
            out.print(ans);
            return;
        }

        for (int i = 1; i < calc.length; i++) {
            // i - common colors
            int power = pow(i, n * (m - 2));
            for (int j = 0; i + j < calc.length; j++) {
                // j - non common colors
                if (k - i - j >= j) {
                    ans += (long) fact[k] * revFact[i] % MOD * revFact[j] % MOD
                            * revFact[j] % MOD * revFact[k - i - 2 * j] % MOD
                            //(long)c(k, i) * c(k - i, j) % MOD * c(k - i - j, j) % MOD
                            * calc[i + j] % MOD * calc[i + j] % MOD
                            * power % MOD;
                    if (ans >= MOD)
                        ans -= MOD;
                    // System.err.println(i + " " + j + " " + ans);
                }
            }
        }

        out.print(ans);

        System.err.println(System.currentTimeMillis() - start);
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