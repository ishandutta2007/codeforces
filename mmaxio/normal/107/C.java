import java.io.*;
import java.util.*;

public class cfRound83_C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int[] set;
    boolean[] used;

    int[] a;
    int[] b;

    int n, m;

    boolean testBit(int mask, int ind) {
        return ((mask >> ind) & 1) == 1;
    }

    long eval(int st) {

        for (int i = 0; i < m; i++)
            if (a[i] < st && b[i] < st && set[a[i]] > set[b[i]])
                return 0;

        int[] unused = new int[n - st];
        // System.err.println(n - st);
        int ptr = 0;
        for (int i = 0; i < n; i++)
            if (!used[i])
                unused[ptr++] = i;

        long[] dp = new long[1 << (n - st)]; // i-th bit means position st + i
                                                // is occupied
        dp[0] = 1;
        for (int mask = 0; mask < dp.length - 1; mask++) {
            int curAdd = unused[Integer.bitCount(mask)];
            for (int i = 0; i < n - st; i++)
                if (!testBit(mask, i)) {
                    boolean canSet = true;
                    for (int j = 0; j < m; j++) {
                        if (a[j] == st + i && b[j] < st && curAdd > set[b[j]]) {
                            canSet = false;
                            break;
                        }
                        if (a[j] < st && b[j] == st + i && set[a[j]] > curAdd) {
                            canSet = false;
                            break;
                        }
                        if (a[j] == st + i && b[j] >= st
                                && testBit(mask, b[j] - st)) {
                            canSet = false;
                            break;
                        }
                    }
                    if (canSet)
                        dp[mask | (1 << i)] += dp[mask];
                }
        }

        return dp[dp.length - 1];

    }

    void solve() throws IOException {
        n = nextInt();
        long x = nextLong() - 2001;

        m = nextInt();

        a = new int[m];
        b = new int[m];

        set = new int[n];
        used = new boolean[n];

        for (int i = 0; i < m; i++) {
            a[i] = nextInt() - 1;
            b[i] = nextInt() - 1;
        }

        //System.err.println(eval(0));

        if (x >= eval(0)) {
            out.println("The times have changed");
            return;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (!used[j]) {
                    set[i] = j;
                    used[j] = true;
                    long tmp = eval(i + 1);
                    if (x >= tmp) {
                        used[j] = false;
                        x -= tmp;
                    } else
                        break;
                }
                if (j == n - 1)
                    throw new AssertionError();
            }

        for (int i : set)
            out.print(i + 1 + " ");

    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new cfRound83_C().inp();
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