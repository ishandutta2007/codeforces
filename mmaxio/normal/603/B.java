import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int MOD = 1_000_000_007;

    void solve() throws IOException {
        int p = nextInt();
        int k = nextInt();

        int ret = 1;

        if (k == 0) {
            for (int i = 1; i < p; i++) {
                ret = (int) ((long) ret * p % MOD);
            }
        } else if (k == 1) {
            for (int i = 0; i < p; i++) {
                ret = (int) ((long) ret * p % MOD);
            }
        } else {
            int len = 1;
            for (int v = k; v != 1; v = (int) ((long) v * k % p)) {
                len++;
            }
            int cycles = (p - 1) / len;
            for (int i = 0; i < cycles; i++) {
                ret = (int) ((long) ret * p % MOD);
            }
        }
        
        out.println(ret);
    }

    B() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B();
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