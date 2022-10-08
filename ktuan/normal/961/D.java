import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {

    int n;
    int[] x, y;

    boolean sameline(int[] x, int[] y, int i, int j, int t) {
        return (y[t] - y[j]) * 1l * (x[j] - x[i]) == (x[t] - x[j]) * 1l * (y[j] - y[i]);
    }

    boolean check(int i, int j) {
        boolean[] b = new boolean[n];
        for (int t = 0; t < n; ++t) {
            if (sameline(x, y, i, j, t)) b[t] = true;
        }
        int[] rx = new int[n];
        int[] ry = new int[n];
        int c = 0;
        for (int t = 0; t < n; ++t) if (!b[t]) {
            rx[c] = x[t];
            ry[c] = y[t];
            if (c >= 2 && !sameline(rx, ry, 0, 1, c)) {
                return false;
            }
            ++c;
        }
        return true;
    }

    public void run() {
        n = nextInt();
        x = new int[n];
        y = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = nextInt();
            y[i] = nextInt();
        }

        if (n <= 3 || (check(0, 1) || check(1, 2) || check(0, 2))) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
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