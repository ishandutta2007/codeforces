import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class BaiD implements Runnable {

  int[] a;
  int[][][] F = new int[88][2][2];

  int go(int pos, int du1, int du2) {
    if (pos == a.length) {
      return (du1 == 0 && du2 == 0) ? 1 : 0;
    }
    if (du1 == 1 && du2 == 0) return 0;
    int res = F[pos][du1][du2];
    if (res != -1) return res;
    res = 0;
    for (int b = 0; b < 2; ++b) {
      int z = b;
      if (du1 == 1 && du2 == 1) z++;
      if (z >= a[pos]) {
        z -= a[pos];
        int d2 = du2;
        if (du1 == 1 && du2 == 1) d2 = 0;
        if (z <= 1) {
          res += go(pos + 1, d2, z);
        }
      }
    }
    return F[pos][du1][du2] = res;
  }

  int solve(int[] a) {
    this.a = a;
    // F = new int[a.length][2][2];
    for (int i = 0; i < a.length; ++i)
      for (int j = 0; j < 2; ++j)
        for (int t = 0; t < 2; ++t)
          F[i][j][t] = -1;
    int res = go(0, 0, 0);
    return res;
  }

  public void run() {
    int t = nextInt();
    long[] fibo = new long[87];
    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i < fibo.length; ++i) {
      fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    StringBuffer res = new StringBuffer();
    for (int i = 0; i < t; ++i) {
      long n = nextLong();
      int[] a = new int[86];
      int fj = 0;
      for (int j = fibo.length - 1; j >= 1; --j) {
        if (n >= fibo[j]) {
          fj = Math.max(j, fj);
          n -= fibo[j];
          a[j - 1] = 1;
        }
      }
      int[] b = new int[fj];
      for (int j = 0; j < b.length; ++j) b[j] = a[j];
      // out.println(solve(b));
      res.append(solve(b));
      res.append('\n');
    }
    out.print(res);
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
        new BaiD().run();
    }
}