import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    public void run() {
        int a = nextInt();
        int b = nextInt();
        int uc = BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();
        int[] r = new int[100000];
        int nr = 0;
        for(int i=1;i*i<=uc;++i) if(uc % i == 0) {
            r[nr++] = i;
            if(i * i < uc)
                r[nr++] = uc / i;
        }
        Arrays.sort(r, 0, nr);
        int q = nextInt();
        for(int i=0;i<q;++i) {
            int low = nextInt();
            int high = nextInt();
            int le = 0, ri = nr - 1;
            while(le < ri) {
                int mi = (le + ri) / 2 + 1;
                if(r[mi] <= high) le = mi;
                else ri = mi - 1;
            }
            if(r[le] >= low)
                System.out.println(r[le]);
            else
                System.out.println(-1);
        }
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