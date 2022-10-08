import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class BaiC implements Runnable {

  boolean canEven(long a, long b) {
    long k = a / b;
    if (b % 2 == 1) {
      return k % 2 == 0;
    }
    else {
      long pos = k % (b + 1);
      return pos % 2 == 0;
    }
  }

  boolean firstWin(long a, long b) {
    if (a < b) {
      long t = a; a = b; b = t;
    }
    if (b == 0) {
      return false;
    }
    if (canEven(a, b)) {
      return true;
    }
    long newa = a % b;
    return !firstWin(b, newa);
  }

  public void run() {
    int t = nextInt();
    for (int i = 0; i < t; ++i) {
      long a = nextLong();
      long b = nextLong();
      boolean fw = firstWin(a, b);
      if (fw) out.println("First");
      else out.println("Second");
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
        new BaiC().run();
    }
}