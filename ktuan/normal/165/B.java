import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.System.out;
// import static java.lang.Math.*;

public class Main implements Runnable {

    public void run() {
      int n = nextInt();
      int k = nextInt();
      int L = 0, R = n;
      while (L < R) {
        int M = (L + R) / 2;
        long total = M;
        for (long z = k; M / z != 0; z *= k) {
          total += M / z;
        }
        if (total >= n) R = M;
        else L = M + 1;
      }
      out.println(L);
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