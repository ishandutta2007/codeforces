import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
    
    
    public void run() {
        int[] k = new int[3];
        int[] t = new int[3];
        for(int i=0;i<3;++i)
            k[i] = nextInt();
        for(int i=0;i<3;++i)
            t[i] = nextInt();
        int n = nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;++i) {
            a[i] = nextInt();
        }
        long[][] lasttime = new long[3][];
        int[] id = new int[3];
        for(int i=0;i<3;++i) {
            lasttime[i] = new long[Math.min(n, k[i])];
        }
        long res = 0;
        for(int i=0;i<n;++i) {
            long z = a[i];
            for(int j=0;j<3;++j) {
                z = Math.max(lasttime[j][id[j]], z) + t[j];
                lasttime[j][id[j]] = z;
                id[j] = (id[j] + 1) % lasttime[j].length;
            }
            res = Math.max( res, z - a[i]);
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
        new BaiB().run();
    }
}