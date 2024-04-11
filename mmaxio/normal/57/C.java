import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int MOD = 1000000007;
    
    int fact[];
    int inv[];
    
    int c(int n, int k) {
        return (int)((long)fact[n] * inv[k] % MOD * inv[n - k] % MOD);
    }
    
    int binPow(int a, int b) {
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
        int n = nextInt();
        
        fact = new int[2 * n];
        inv = new int[2 * n];
        
        fact[0] = 1;
        for (int i = 1; i < 2 * n; i++)
            fact[i] = (int)((long)fact[i - 1] * i % MOD);
        
        for (int i = 0; i < 2 * n; i++)
            inv[i] = binPow(fact[i], MOD - 2);
        
        
        //int res = n;
        
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += c(2 * n - i - 1, n - 1);
            if (res >= MOD)
                res -= MOD;
        }
        
        res += res;
        if (res >= MOD)
            res -= MOD;
        
        res -= n;
        if (res < 0)
            res += MOD;
        
        out.print(res);
            
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