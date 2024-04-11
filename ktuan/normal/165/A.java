import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class Main implements Runnable {

    public void run() {
      int n = nextInt();
      int[] x = new int[n];
      int[] y = new int[n];
      for (int i = 0; i < n; ++i) {
        x[i] = nextInt();
        y[i] = nextInt();
      }
      int res = 0;
      for (int i = 0; i < n; ++i) {
        boolean c1, c2, c3, c4;
        c1 = c2 = c3 = c4 = false;
        for (int j = 0; j < n; ++j) if (j != i) {
          if (x[j] == x[i] && y[j] > y[i]) c1 = true;
          if (x[j] == x[i] && y[j] < y[i]) c2 = true;
          if (y[j] == y[i] && x[j] > x[i]) c3 = true;
          if (y[j] == y[i] && x[j] < x[i]) c4 = true;
        }
        if (c1 && c2 && c3 && c4) ++res;
      }
      out.println(res);
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