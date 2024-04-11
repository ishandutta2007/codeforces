import java.io.*;
import java.util.*;

public class D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int MOD = 1000000007;

    static class Man implements Comparable<Man> {
        int howMany, pos;

        public Man(int howMany, int pos) {
            this.howMany = howMany;
            this.pos = pos;
        }

        @Override
        public int compareTo(Man o) {
            return -Integer.compare(howMany, o.howMany);
        }
    }

    Man[] d;
    int know;

    int[] pow2;

    int f(int x, int y) {
        if (x < 0 || y < 0)
            return 0;
        return (int) ((long) fact[x + y] * invFact[x] % MOD * invFact[y] % MOD);
    }

    int[] fact;
    int[] invFact;

    int go(int l, int r, int next) {
        // System.err.println(l + " " + r + " " + next);
        int len = r - l + 1;
        if (next == know) {
            if (len == 0) {
                throw new AssertionError();
            }
            return pow2[len - 1];
        }
        int pos = d[next].pos;
        int howMany = d[next].howMany;

        if (pos < l || pos > r)
            return 0;

        int szL = pos - l;
        int szR = r - pos;

        if (howMany == 1) {
            return f(szL, szR);
        }

        int diff = len - howMany;

        int ret = 0;

        // he will be on the left
        do {
            int takeL = szL;
            int takeR = diff - szL;
            if (takeR < 0)
                continue;
            ret += (int) ((long) f(takeL, takeR)
                    * go(pos + 1, r - takeR, next + 1) % MOD);
            if (ret >= MOD)
                ret -= MOD;
        } while (false);

        // he will be on the right
        do {
            int takeR = szR;
            int takeL = diff - szR;
            if (takeL < 0)
                continue;
            ret += (int) ((long) f(takeL, takeR)
                    * go(l + takeL, pos - 1, next + 1) % MOD);
            if (ret >= MOD)
                ret -= MOD;
        } while (false);

        return ret;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];

        know = 0;

        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            if (a[i] > 0) {
                know++;
            }
        }

        d = new Man[know];
        for (int i = 0, j = 0; i < n; i++) {
            if (a[i] > 0) {
                d[j++] = new Man(a[i], i);
            }
        }

        System.err.println(know);

        Arrays.sort(d);

        pow2 = new int[n + 1];
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }

        fact = new int[n + 1];
        invFact = new int[n + 1];
        fact[0] = invFact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (int) ((long) fact[i - 1] * i % MOD);
            invFact[i] = pow(fact[i], MOD - 2);
        }

        out.println(go(0, n - 1, 0));

    }

    int pow(int a, int b) {
        int ret = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret = (int) ((long) ret * a % MOD);
            }
            a = (int) ((long) a * a % MOD);
            b >>= 1;
        }
        return ret;
    }

    D() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D();
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