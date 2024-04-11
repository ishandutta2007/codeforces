import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class BaiA implements Runnable {

  public void run() {
    int n = nextInt();
    double a = nextDouble();
    double d = nextDouble();
    double lasttime = -1;
    for (int i = 0; i < n; ++i) {
      double t = nextDouble();
      double v = nextDouble();
      double arrive_time = 0;
      if (d <= v * v / 2 / a) {
        arrive_time = t + Math.sqrt(d * 2 / a);
      } else {
        double rem = d - v * v / 2 / a;
        arrive_time = t + v / a + rem / v;
      }
      lasttime = arrive_time = Math.max(arrive_time, lasttime);
      out.printf("%.5f\n", arrive_time);
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
        new BaiA().run();
    }
}