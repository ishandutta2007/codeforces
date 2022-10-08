import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

    public void run() {
//        try { keyboard = new BufferedReader(new FileReader("/Users/anhk/code/in")); } catch (FileNotFoundException e) { e.printStackTrace(); }
        keyboard = new BufferedReader(new InputStreamReader(System.in));
        int a = nextInt();
        int b = nextInt();
        int left = 0, right = 100000;
        while (left < right) {
            int mid = (left + right) / 2 + 1;
            if (check(mid, a, b) != null) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        int[][] res = check(left, a, b);
        for (int i = 0; i < 2; ++i) {
            System.out.println(res[i].length);
            for (int j = 0; j < res[i].length; ++j) {
                System.out.print(res[i][j] + " ");
            }
            System.out.println();
        }
    }

    int[][] check(int total, int a, int b) {
        ArrayList<Integer> listA = new ArrayList<>();
        ArrayList<Integer> listB = new ArrayList<>();
        while (total > 0) {
            if (a < b) {
                if (b >= total) {
                    listB.add(total);
                    b -= total;
                } else {
                    return null;
                }
            } else {
                if (a >= total) {
                    listA.add(total);
                    a -= total;
                } else {
                    return null;
                }
            }
            --total;
        }
        int[][] res = new int[2][];
        res[0] = toInts(listA);
        res[1] = toInts(listB);
        return res;
    }

    int[] toInts(ArrayList<Integer> list) {
        int[] res = new int[list.size()];
        for (int i = 0; i < res.length; ++i) {
            res[i] = list.get(i);
        }
        return res;
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