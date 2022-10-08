import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    class Data {
        long total, left, right, mid;
        Data(long x) {
            total = left = right = mid = x;
        }
        Data() {}
        Data add(Data d) {
            Data r = new Data();
            r.total = total + d.total;
            r.left = left;
            if(r.left < total + d.left) r.left = total + d.left;
            r.right = d.right;
            if(r.right < d.total + right) r.right = d.total + right;
            r.mid = Math.max(mid, d.mid);
            if(r.mid < right + d.left)
                r.mid = right + d.left;
            return r;
        }
    }
    
    public void run() {
        int n = nextInt();
        int m = nextInt();
        Data[] d = new Data[n];
        for(int i=0;i<n;++i) {
            int k = nextInt();
            for(int j=0;j<k;++j) {
                int x = nextInt();
                if(d[i] == null) d[i] = new Data(x);
                else d[i] = d[i].add(new Data(x));
            }
        }
        Data res = null;
        for(int i=0;i<m;++i) {
            int id = nextInt() - 1;
            if(res == null) res = d[id];
            else res = res.add(d[id]);
        }
        System.out.println(res.mid);
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