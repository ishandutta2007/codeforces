import java.io.*;
import java.util.*;

public class D_new {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    long n;
    int bitLen, MOD;

    long cntNumber(int curLen, long curRem) {
        // #x : 0 <= x <= n, last curLen bits of x = curRem

        long tmp = n - curRem;
        if (tmp < 0)
            return 0;

        return (tmp >> curLen) + 1;

    }

    int aux(int curLen, long curRem, long y) {
        // like in cntNumber, but they must be <= y
        // return number of them + sum of them

        y = Math.min(y, n);
        y -= curRem;
        if (y < 0)
            return 0;

        y >>= curLen;

        int res = (int) ((y + 1) % MOD * ((curRem + 1) % MOD) % MOD);
        
        long mult = (1L << curLen) % MOD;

        if (y % 2 == 0)
            res += (int) (y / 2 % MOD * ((y + 1) % MOD) % MOD * mult % MOD);
        else
            res += (int) (y % MOD * ((y + 1) / 2 % MOD) % MOD * mult % MOD);
        
        if (res >= MOD)
            res -= MOD;
        
        return res;

    }

    int go(long x, long y) {
        // 0 <= c <= x, 0 <= rev(c) <= y
        // return sum of such rev(c) + number of such rev(c)

        if (x == -1 || y == -1)
            return 0;

        x++;
        int curLen = 0;
        long curRem = 0;
        // x is a number of required numbers

        int res = 0;

        while (x > 0) {
            long cntZero = cntNumber(curLen + 1, curRem);

            if (x >= cntZero) {
                res += aux(curLen + 1, curRem, y);
                if (res >= MOD)
                    res -= MOD;
                x -= cntZero;
                curRem |= 1L << curLen;
            }

            curLen++;

        }

        return res;
    }

    void solve() throws IOException {
        n = nextLong() - 1;
        int m = nextInt();
        MOD = nextInt();

        bitLen = Long.bitCount(Long.highestOneBit(n - 1) - 1) + 1;

        for (int i = 0; i < m; i++) {
            long l = nextLong() - 1;
            long r = nextLong() - 1;
            long u = nextLong() - 1;
            long v = nextLong() - 1;

            int ans = go(r, v) - go(l - 1, v) - go(r, u - 1) + go(l - 1, u - 1);

            ans = (ans % MOD + MOD) % MOD;
            out.println(ans);
        }
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D_new().inp();
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