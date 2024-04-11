import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int[] MAGIC = { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127,
            521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213,
            19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839,
            859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917,
            20996011 };

    // boolean test(int z) {
    // for (int x = 1; x + 1<= z; x++) {
    // int A = x + 1;
    // int B = x >> 1;
    // if (z % A == B && z >= A + B)
    // return false;
    // }
    // return true;
    // }
    
    static final int MOD = 1000000007;
    
    int pow(int a, int b) {
        int res = 1;
        while (b != 0) {
            if ((b & 1) == 1)
                res = (int)((long)res * a % MOD);
            a = (int)((long)a * a % MOD);
            b >>= 1;
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt() - 1;
        int res = pow(2, MAGIC[n] - 1);
        res--;
        if (res < 0)
            res += MOD;
        out.println(res);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
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