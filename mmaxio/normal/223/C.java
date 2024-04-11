import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int MOD = 1000000007;

    int pow(int a, int b) {
        int res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (int) ((long) res * a % MOD);
            a = (int)((long)a * a % MOD);
            b >>= 1;
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();

        int[] a = new int[n];

        for (int i = 0; i < n; i++)
            a[i] = nextInt();

        if (k == 0) {
            for (int i = 0; i < n; i++)
                out.print(a[i] + " ");
            out.println();
            return;
        }

        k--;

        int[] mult = new int[n];
        mult[0] = 1;
        for (int i = 1; i < n; i++)
            mult[i] = (int) ((long) mult[i - 1] * (k + i) % MOD * pow(i, MOD - 2) % MOD);

        int[] res = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; i + j < n; j++) {
                res[i + j] += (int)((long)a[i] * mult[j] % MOD);
                if (res[i + j] >= MOD)
                    res[i + j] -= MOD;
            }
        
        for (int i = 0; i < n; i++)
            out.print(res[i]  + " ");
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