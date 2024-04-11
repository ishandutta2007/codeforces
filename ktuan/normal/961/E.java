import java.io.*;
import java.util.*;
import java.math.*;

public class Solution implements Runnable {

    int n;
    int[] a;
    long[] b;

    long count(int i) {
        i = Math.min(i, n);
        long res = 0;
        for (;i >= 1; i -= (i & (-i))) res += b[i];
        return res;
    }

    void add(int i, int d) {
        for(; i <= n; i += (i & (-i))) b[i] += d;
    }

    public void run() {
        // try { keyboard = new BufferedReader(new FileReader("/Users/anhk/code/in")); } catch (FileNotFoundException e) { e.printStackTrace(); }
        keyboard = new BufferedReader(new InputStreamReader(System.in));

        n = nextInt();
        a = new int[n + 1];
        for (int i = 1; i <= n; ++i)
            a[i] = nextInt();

        ArrayList<Integer>[] valueList = new ArrayList[n + 1];
        for (int i = 1; i <= n; ++i)
            valueList[i] = new ArrayList<Integer>();
        for (int i = 1; i <= n; ++i)
            valueList[Math.min(a[i], n)].add(i);

        b = new long[n + 1];
        long result = 0;

        for (int i = 1; i <= n; ++i) {
            if (i > 1) {
                for (Integer v: valueList[i - 1]) {
                    if (v < i) add(v, -1);
                }
            }
            result += count(a[i]); // index <= a[i], value >= i;
            if (a[i] >= i) add(i, 1);
        }

        System.out.println(result);
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