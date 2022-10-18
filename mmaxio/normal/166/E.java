import java.io.*;
import java.util.*;

public class E {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    static final int MOD = 1000000007;
    static final int N = 2;
    static final int[][] A = {{0, 1}, {3, 2}};
    
    int[][] matrMul(int[][] a, int[][] b) {
        int[][] c = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++) {
                    c[i][j] += (int)((long)a[i][k] * b[k][j] % MOD);
                    if (c[i][j] >= MOD)
                        c[i][j] -= MOD;
                }
        return c;
    }
    
    int[][] matrPow(int[][] a, int b) {
        int[][] res = new int[N][N];
        for (int i = 0; i < N; i++)
            res[i][i] = 1;
        
        while (b > 0) {
            if ((b & 1) == 1)
                res = matrMul(res, a);
            a = matrMul(a, a);
            b >>= 1;
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int[][] res = matrPow(A, n);
        out.println(res[0][0]);
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