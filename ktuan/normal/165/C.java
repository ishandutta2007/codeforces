import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class Main implements Runnable {

    public void run() {
      int k = nextInt();
      char[] a = nextStr().toCharArray();
      int n = a.length;
      int j = -1;
      int c1 = 0;
      long total = 0;
      int[] next = new int[n + 1];
      next[n] = n;
      for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n && a[i + 1] == '1') next[i] = i + 1;
        else next[i] = next[i + 1];
      }
      for (int i = 0; i < n; ++i) {
        if (j < i) {
          j = i;
          c1 = a[i] == '1' ? 1 : 0;
        }
        while (c1 < k && j + 1 < n) {
          ++j;
          if (a[j] == '1') ++c1;
        }
        if (c1 == k) {
          total += next[j] - j;
        }
        if (a[i] == '1') --c1;
      }
      out.println(total);
    }

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