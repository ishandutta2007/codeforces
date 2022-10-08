import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    Map<String, Integer> ma;
    int nma;
    
    int getId(String s) {
        if(ma.containsKey(s))
            return ma.get(s);
        else {
            ma.put(s, nma++);
            return ma.get(s);
        }
    }
    
    int[][] a;
    
    int cb(int b) {
        int r = 0;
        for(int i=0;i<10;++i)
            if((b&(1<<i))!=0) ++r;
        return r;
    }
    
    int calc(int x, int b1, int y, int b2) {
        x /= cb(b1);
        y /= cb(b2);
        return Math.abs(x-y);
    }
    
    int cc(int b) {
        int r = 0;
        for(int i=0;i<7;++i) if((b&(1<<i))!=0)
            for(int j=0;j<7;++j) if((b&(1<<j))!=0)
                if(i!=j)
                    r+=a[i][j];
        return r;                   
    }
    
    public void run() {
        ma = new TreeMap<String, Integer>();
        nma = 0;
        int n = nextInt();
        a = new int[7][7];
        for(int i=0;i<n;++i) {
            String s1 = nextStr();
            String ss = nextStr();
            String s2 = nextStr();
            a[getId(s1)][getId(s2)]++;
        }
        int x = nextInt(), y = nextInt(), z = nextInt();
        int bdif = 2000000001, blike = -1;
        for(int b1=1;b1<1<<7;++b1)
            for(int b2=1;b2<1<<7;++b2)
                if((b1 & b2) == 0 && (b1 | b2) != ((1<<7)-1)) {
                    int b3 = ((1<<7)-1) ^ b1 ^ b2;
                    int dif = Math.max(calc(x,b1,y,b2), Math.max(calc(x,b1,z,b3), calc(y,b2,z,b3)));
                    int like = cc(b1) + cc(b2) + cc(b3);
                    if(bdif > dif || (bdif == dif && blike < like)) {
                        bdif = dif;
                        blike = like;
                    }
                }
        System.out.println(bdif + " " + blike);
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