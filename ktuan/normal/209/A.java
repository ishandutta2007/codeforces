import java.io.*;
import java.util.*;
import java.math.*;

public class Solution implements Runnable {
    public void run() {
        // try { keyboard = new BufferedReader(new FileReader("/Users/anhk/code/in")); } catch (FileNotFoundException e) { e.printStackTrace(); }
        keyboard = new BufferedReader(new InputStreamReader(System.in));
        int n = nextInt();
        long mod = 1000000007;
        long[] f = new long[2];
        long total = 0;
        for (int i = 0; i < n; ++i) {
            long res = 1;
            res = (res + f[1 - i % 2]) % mod;
            f[i % 2] = (f[i % 2] + res) % mod;
            total = (total + res) % mod;
        }
        System.out.println(total);
    }

    BufferedReader keyboard = null;
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
        new Solution().run();
    }
}