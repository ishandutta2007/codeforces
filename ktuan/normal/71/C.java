import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    public void run() {
        int n = nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;++i)
            a[i] = nextInt();
        boolean[] isprime = new boolean[n+1];
        Arrays.fill(isprime,true);
        isprime[0] = isprime[1] = false;
        for(int i=2;i<=n;++i) if(isprime[i]) {
            for(int j=i+i;j<=n;j+=i)
                isprime[j] = false;
        }
        if(n >= 4) isprime[4] = true;
        for(int i=3;i<=n;++i) if(isprime[i] && n % i == 0) {
            int step = n / i;
            for(int s=0;s<step;++s) {
                boolean ok = true;
                for(int j=s;j<n;j+=step) if(a[j] == 0) {
                    ok = false;
                    break;
                }
                if(ok) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
        return;
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