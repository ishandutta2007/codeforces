import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class BaiA implements Runnable {

    static PrintStream out = System.out;

    public void run() {
      int n = nextInt();
      int[] x = new int[n];
      int[] y = new int[n];
      for (int i = 0; i < n; ++i) {
        x[i] = nextInt();
        y[i] = nextInt();
      }
      boolean[][] ke = new boolean[n][n];
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (x[i] == x[j] || y[i] == y[j]) ke[i][j] = true;
        }
      }
      for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            if (ke[i][k] && ke[k][j]) ke[i][j] = true;

      boolean[] mark = new boolean[n];
      int stp = 0;
      for (int i = 0; i < n; ++i) if (!mark[i]) {
        ++stp;
        for (int j = i; j < n; ++j) if (ke[i][j]) mark[j] = true;
      }
      out.println(stp - 1);
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
        new BaiA().run();
    }
}