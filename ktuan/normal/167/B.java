import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class BaiB implements Runnable {

  int n, L, K;
  double[][][] F;
  double[] p;
  int[] a;

  double calc(int i, int j, int k) {
    if (i == n) {
      return (j <= 0 && k >= 0) ? 1.0 : 0;
    }
    if (j < 0) j = 0;
    if (k >= n) k = n;
    double res = F[i][j][k + n];
    if (res >= -0.5) return res;
    res = 0;
    // win
    res += p[i] * calc(i + 1, j - 1, k + a[i]);
    // lose
    res += (1 - p[i]) * calc(i + 1, j, k);
    // viet(i,j,k,res);
    return F[i][j][k + n] = res;
  }

  public void run() {
    n = nextInt();
    L = nextInt();
    K = nextInt();
    p = new double[n];
    a = new int[n];
    for (int i = 0; i < n; ++i) {
      p[i] = nextDouble();
      p[i] /= 100.0;
    }
    for (int i = 0; i < n; ++i) {
      a[i] = nextInt();
    }
    
    F = new double[n][L + 1][444];
    for (double[][] a2 : F) for (double[] a1 : a2) Arrays.fill(a1, -1);
    
    double res = calc(0, L, K);
    out.printf("%.7f\n", res);
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
        new BaiB().run();
    }
}