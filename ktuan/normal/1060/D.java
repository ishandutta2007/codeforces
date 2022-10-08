import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

    public void run() {
//        try { keyboard = new BufferedReader(new FileReader("/Users/anhk/code/in")); } catch (FileNotFoundException e) { e.printStackTrace(); }
        keyboard = new BufferedReader(new InputStreamReader(System.in));
        int n = nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        long res = n;
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
            b[i] = nextInt();
            res += a[i] + b[i];
        }
        Arrays.sort(a);
        Arrays.sort(b);
        for (int i = 0; i < n; ++i) {
            res = res - Math.min(a[i], b[i]);
        }
        System.out.println(res);
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