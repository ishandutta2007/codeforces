import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    long calc(long[] x) {
        long t = 0, r = 0;
        for(int i=0;i<x.length;++i)
        {
            r += x[i] * x[i] * (x.length - 1);
            t += x[i];
        }
        r *= 2;
        for(int i=0;i<x.length;++i)
            r -= 2 * x[i] * (t - x[i]);
        return r;
    }
    
    public void run() {
        int n = nextInt();
        long[] x = new long[n];
        long[] y = new long[n];
        for(int i=0;i<n;++i) {
            x[i] = nextLong();
            y[i] = nextLong();
        }
        long total = 0;
        total += calc(x) + calc(y);
        System.out.println(total / 2);
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