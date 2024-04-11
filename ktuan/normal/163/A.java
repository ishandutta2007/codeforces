import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class Main implements Runnable {

    final int mod = 1000000007;

    char[] a, b;
    int m, n;
    int[][][] F;

    int calc(int i, int j, int needi) {
      if (i < 0 || j < 0) return 1;
      int res = F[i][j][needi];
      if (res != -1) return res;
      res = 0;
      if (a[i] == b[j]) {
        res += calc(i - 1, j - 1, 1);
        res %= mod;
      }
      res += calc(i, j - 1, needi);
      res %= mod;
      if (needi == 0) {
        res += calc(i - 1, j, 0);
        res %= mod;
        res -= calc(i - 1, j - 1, 0);
        res %= mod;
        res += mod;
        res %= mod;
      }
      viet(i, j, needi, res);
      return F[i][j][needi] = res;
    } 

    public void run() {
      a = nextStr().toCharArray();
      b = nextStr().toCharArray();
      m = a.length;
      n = b.length;
      /* F = new int[m + 1][n + 1][2];
      for (int[][] a2 : F) for (int[] a1 : a2) Arrays.fill(a1, -1);
      int res = (calc(m - 1, n - 1, 0) - 1 + mod) % mod;
      out.println(res); */
      int[][] F = new int[n][2];
      int[][] G = new int[n][2];
      for (int[] a1 : F) Arrays.fill(a1, 1);
      for (int i = 0; i < m; ++i) {
        for (int[] a1 : G) Arrays.fill(a1, 0);
        for (int j = 0; j < n; ++j) {
          for (int needi = 0; needi < 2; ++needi) {
            if (a[i] == b[j]) {
              G[j][needi] = (G[j][needi] + (j > 0 ? F[j - 1][1] : 1)) % mod;
            }
            G[j][needi] = (G[j][needi] + (j > 0 ? G[j - 1][needi] : 1)) % mod;
            if (needi == 0) {
              G[j][needi] = (G[j][needi] + F[j][0]) % mod;
              G[j][needi] = (G[j][needi] - (j > 0 ? F[j - 1][0] : 1) + mod) % mod;
            }
            // viet(i, j, needi, G[j][needi]);
          }
        }
        int[][] tmp = F; F = G; G = tmp;
      }
      out.println((F[n - 1][0] - 1 + mod) % mod);
    }

    int[] ar(int st, int en) { int[] res = new int[Math.max(en - st, 0)]; for (int i = st; i < en; ++i) res[i - st] = i; return res; }
    int[] ar(int n) { return ar(0, n); }
    void viet(Object...os) { System.err.println(Arrays.deepToString(os)); }
    BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer strtok = null;

    String nextStr() {
        try {
            while(strtok == null || !strtok.hasMoreTokens())
                strtok = new StringTokenizer(keyboard.readLine());
            return strtok.nextToken();
        }
        catch(Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
            return null;
        }
    }

    int nextInt() {
        return Integer.parseInt(nextStr());
    }

    long nextLong() {
        return Long.parseLong(nextStr());
    }

    double nextDouble() {
        return Double.parseDouble(nextStr());
    }

    public static void main(String[] args) {
        new Main().run();
    }
}