import java.io.*;
import java.util.*;

public class cfRound83_D {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;
    
    final int MOD = 12345;
    
    int[][] mul(int[][] a, int[][] b) {
        int[][] res = new int[sz][sz];
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++) {
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= MOD;
                }
        
        
        return res;
    }
    
    int[][] power(int[][] a, long b) {
        if (b == 0) {
            int[][] res = new int[sz][sz];
            for (int i = 0; i < sz; i++)
                res[i][i] = 1;
            return res;
        }
        
        if ((b & 1) == 1)
            return mul(a, power(a, b - 1));
        
        int[][] tmp = power(a, b >> 1);
            return mul(tmp, tmp);
        
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int lcm(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        
        return a / gcd(a, b) * b;
    }
    
    int sz;

    void solve() throws IOException {
        long n = nextLong();
        
        ArrayList<Integer>[] list = new ArrayList[26];
        for (int i = 0; i < 26; i++)
            list[i] = new ArrayList<Integer>();
        
        int c = nextInt();
        
        for (int i = 0; i < c; i++) {
            String s = nextToken();
            int x = nextInt();
            list[s.charAt(0) - 'A'].add(x);
        }
        
        ArrayList<Integer> can = new ArrayList<Integer>();
        ArrayList<Integer> mult = new ArrayList<Integer>();
        ArrayList<Integer> lcm = new ArrayList<Integer>();
        
        sz = 1;
        
        for (int i = 0; i < 26; i++)
            if (!list[i].isEmpty()) {
                int curLcm = 0;
                for (int x : list[i])
                    curLcm = lcm(curLcm, x);
                can.add(i);
                mult.add(sz);
                sz *= curLcm;
                lcm.add(curLcm);
            }
        
        mult.add(sz);
        
//      System.err.println(can);
//      System.err.println(mult);
//      System.err.println(lcm);
        
        int[][] matr = new int[sz][sz];
        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < can.size(); j++) {
                int oldRem = i % mult.get(j + 1) / mult.get(j);
                int newRem = (oldRem + 1) % lcm.get(j);
                matr[i - oldRem * mult.get(j) + newRem * mult.get(j)][i]++;
            }
        }
        
        matr = power(matr, n);
        
        int ans = 0;
        
        for (int i = 0; i < sz; i++) {
            boolean goodTotalRem = true;
            for (int j = 0; j < can.size(); j++) {
                int curRem = i % mult.get(j + 1) / mult.get(j);
                boolean goodRem = false;
                for (int good : list[can.get(j)])
                    if (curRem % good == 0) {
                        goodRem = true;
                        break;
                    }
                if (!goodRem) {
                    goodTotalRem = false;
                    break;
                }
            }
            if (goodTotalRem) {
                ans += matr[i][0];
                if (ans >= MOD)
                    ans -= MOD;
            }
        }
        
        out.println(ans);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new cfRound83_D().inp();
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