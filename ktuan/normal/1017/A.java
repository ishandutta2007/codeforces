import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

    public void run() {
//        try { keyboard = new BufferedReader(new FileReader("/Users/anhk/code/in")); } catch (FileNotFoundException e) { e.printStackTrace(); }
        keyboard = new BufferedReader(new InputStreamReader(System.in));
        int n = nextInt();
        int[][] a = new int[n][5];
        for (int i = 0; i < n; ++i) {
            a[i][0] = i;
            for (int j = 1; j < 5; ++j) a[i][j] = nextInt();
        }
        Arrays.sort(a, (int[] o1, int[] o2) -> {
            int s1 = 0, s2 = 0;
            for (int i = 1; i < 5; ++i) {
                s1 += o1[i];
                s2 += o2[i];
            }
            if (s1 == s2) return o1[0] - o2[0];
            else return s2 - s1;
        });
        int res = 0;
        for (int i = 0; i < n; ++i) if (a[i][0] == 0) res = i;
        System.out.println(res + 1);
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