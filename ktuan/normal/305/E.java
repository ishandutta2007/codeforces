import java.io.*;
import java.util.*;
import java.math.*;

public class Solution implements Runnable {
    public void run() {
        // try { keyboard = new BufferedReader(new FileReader("/Users/anhk/code/in")); } catch (FileNotFoundException e) { e.printStackTrace(); }
        keyboard = new BufferedReader(new InputStreamReader(System.in));

        String s = nextStr();
        F = new int[s.length() + 1];
        Arrays.fill(F, -1);
        if (g(s) > 0) {
            System.out.println("First");
            for (int i = 1; i + 1 < s.length(); ++i) {
                if (s.charAt(i - 1) == s.charAt(i + 1) && (g(s.substring(0, i)) ^ g(s.substring(i + 1, s.length()))) == 0) {
                    System.out.println(i + 1);
                    break;
                }
            }
        } else {
            System.out.println("Second");
        }
    }

    int[] F;

    int f(int n) {
        if (n == 0) return 0;
        if (F[n] == -1) {
            boolean[] b = new boolean[n + 1];
            for (int i = 0; i < n; ++i) {
                int left = Math.max(i - 1, 0);
                int right = Math.max(n - i - 2, 0);
                b[f(left) ^ f(right)] = true;
            }
            for (int i = 0; i <= n; ++i)
                if (!b[i]) {
                    F[n] = i;
                    break;
                }
        }
        return F[n];
    }

    int g(String s) {
        int n = s.length();
        boolean[] canCut = new boolean[n];
        for (int i = 1; i + 1 < n; ++i)
            if (s.charAt(i - 1) == s.charAt(i + 1))
                canCut[i] = true;
        int currentLength = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (canCut[i]) {
                currentLength++;
            } else {
                res = res ^ f(currentLength);
                currentLength = 0;
            }
        }
        if (currentLength > 0) res = res ^ f(currentLength);
        return res;
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