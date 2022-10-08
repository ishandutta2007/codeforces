import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {

    public void run() {
//        try { keyboard = new BufferedReader(new FileReader("/Users/anhk/code/in")); } catch (FileNotFoundException e) { e.printStackTrace(); }
        keyboard = new BufferedReader(new InputStreamReader(System.in));
        String s = nextStr();
        int n = s.length();
        StringBuilder sb = new StringBuilder();
        int c1 = 0;
        for (int i = 0; i < n; ++i) if (s.charAt(i) == '1') ++c1;
        boolean appendedOne = false;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '2' && !appendedOne) {
                appendedOne = true;
                for (int j = 0; j < c1; ++j) sb.append('1');
            }
            if (s.charAt(i) != '1') {
                sb.append(s.charAt(i));
            }
        }
        if (!appendedOne) {
            for (int j = 0; j < c1; ++j) sb.append('1');
        }
        System.out.println(sb.toString());
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