import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    public void run() {
        int n = nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;++i)
            a[i] = nextInt();
        long res = 0;
        for(int i=0;i<n;++i) {
            int j = i;
            while(j < n && a[j] == a[i]) ++j;
            long c = j - i;
            res += c * (c + 1) / 2;
            i = j - 1;
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
        new BaiA().run();
    }
}