import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class BaiB implements Runnable {

  class Lem implements Comparable<Lem> {
    int id;
    int m, v;

    public int compareTo(Lem x) {
      if (m == x.m) {
        return v - x.v;
      }
      return m - x.m;
    }
  }

  Lem[] a;
  int n, k, h;

  public void run() {
    n = nextInt();
    k = nextInt();
    h = nextInt();
    a = new Lem[n];
    try {
      String[] tmp = keyboard.readLine().split(" ");
      String[] tmp2 = keyboard.readLine().split(" ");
      for (int i = 0; i < n; ++i) {
        a[i] = new Lem();
        a[i].id = i + 1;
        a[i].m = Integer.parseInt(tmp[i]);
        a[i].v = Integer.parseInt(tmp2[i]);
      }
    } catch (Exception ex) {}
    Arrays.sort(a);
    // for (int i = 0; i < n; ++i) viet(a[i].m, a[i].v);
    double L = 0, R = 1100000000;
    for (int t = 0; t < 111; ++t) {
      double mid = (L + R) / 2;
      double cur_k = 1;
      for (int i = 0; i < n; ++i) {
        if (cur_k * h / a[i].v <= mid) {
          cur_k = cur_k + 1;
        }
        if (cur_k > k) break;
      }
      if (cur_k > k) R = mid;
      else L = mid;
    }
    {
      int[] res = new int[k];
      double cur_k = 1;
      for (int i = 0; i < n; ++i) {
        if (cur_k * h / a[i].v <= R) {
          res[(int)(cur_k - 0.9)] = a[i].id;
          cur_k = cur_k + 1;
        }
        // viet(i, cur_k);
        if (cur_k > k) break;
      }
      for (int i = 0; i < k; ++i) {
        System.out.print(res[i] + " ");
      }
    }
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