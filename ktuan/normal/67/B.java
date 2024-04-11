import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
    
    public void run() {
        int n = nextInt();
        int k = nextInt();
        int[] b = new int[n];
        for(int i=0;i<n;++i)
            b[i] = nextInt();
        int[] a = new int[n];
        boolean[] mark = new boolean[n];
        for(int i=0;i<n;++i) {
            for(int x=0;x<n;++x) if(!mark[x] && b[x] == 0) {
                boolean ok = true;
                for(int j=0;j<=x-k;++j)
                    if(!mark[j] && b[j] <= 0)
                    {
                        ok = false;
                        break;
                    }
                if(ok) {
                    a[i] = x;
                    mark[x] = true;
                    for(int j=0;j<=x-k;++j)
                        if(!mark[j])
                            --b[j];
                    break;
                }
            }
        }
        for(int i=0;i<n;++i) System.out.print((a[i] + 1) + " ");
    }
    
    public static void main(String[] args) {
        new BaiB().run();
    }

    BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = null;
    
    String nextStr() {
        try {
            if(st == null || !st.hasMoreTokens())
                st = new StringTokenizer(kb.readLine());
            return st.nextToken();
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
}