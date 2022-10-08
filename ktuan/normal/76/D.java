import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    int[] read() {
        BigInteger b = new BigInteger(nextStr());
        String s = b.toString(2);
        int[] r = new int[64];
        int t = 0;
        for(int i=s.length()-1;i>=0;--i) {
            r[t++] = s.charAt(i) == '0' ? 0 : 1;
        }
        return r;
    }
    
    BigInteger tobigint(int[] x) {
        BigInteger res = BigInteger.ZERO;
        for(int i=63;i>=0;--i) {
            res = res.multiply(BigInteger.valueOf(2));
            res = res.add(BigInteger.valueOf(x[i]));
        }
        return res;
    }
    
    public void run() {
        BigInteger a = new BigInteger(nextStr());
        int[] b = read();
        int[] x = new int[64];
        int[] y = new int[64];
        for(int i=63;i>=0;--i) {
            if(b[i] == 1) {
                x[i] = 0; y[i] = 1;
            }
            else {
                x[i] = y[i] = 1;
                if(tobigint(x).add(tobigint(y)).compareTo(a) <= 0) {
                    
                }
                else {
                    x[i] = y[i] = 0;
                }
            }
        }
        if(tobigint(x).add(tobigint(y)).compareTo(a) == 0)
            System.out.println(tobigint(x) + " " + tobigint(y));
        else
            System.out.println(-1);
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