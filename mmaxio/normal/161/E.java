import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    // int[] PRIMES;
    // static final int PRIMES_COUNT = 9592;
    static final int MAXN = 100000;
    static final int[] POW10 = { 1, 10, 100, 1000, 10000 };
    boolean[] isPrime;

    void preCalc() {
        isPrime = new boolean[MAXN + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= MAXN; i++)
            if (isPrime[i])
                for (int j = i * i; j <= MAXN; j += i)
                    isPrime[j] = false;
    }

    int[][] f;
    int res, n;
    int[] val;

    void go(int i, int j, int cur) {
        if (i == n) {
            res += cur;
            return;
        }
        if (j == n) {
            int cnt = 0;
            for (int k = 0; k < 10; k++)
                if (isPrime[val[i] + k * POW10[n - i - 1]])
                    cnt++;
            if (cnt == 0)
                return;
            go(i + 1, i + 2, cur * cnt);
            return;
        }
        for (int k = 0; k < 10; k++) {
            f[i][j] = f[j][i] = k;
            val[i] += k * POW10[n - j - 1];
            val[j] += k * POW10[n - i - 1];
            go(i, j + 1, cur);
            val[i] -= k * POW10[n - j - 1];
            val[j] -= k * POW10[n - i - 1];
        }
    }

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        n = s.length;
        f = new int[n][n];
        val = new int[n];
        for (int i = 0; i < n; i++)
            f[0][i] = f[i][0] = s[i] - '0';
        for (int i = 1; i < n; i++)
            val[i] = f[i][0] * POW10[n - 1];
        res = 0;
        go(1, 2, 1);
        out.println(res);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        preCalc();
        int tests = nextInt();
        while (tests-- > 0)
            solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new E().inp();
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