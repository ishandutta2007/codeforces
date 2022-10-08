import java.io.*;
import java.util.*;
import java.math.*;

public class BaiD implements Runnable {
    
    public void run() {
        int n = nextInt();
        int[] pos = new int[n+1];
        for(int i=0;i<n;++i)
            pos[nextInt()] = i;
        int[] a = new int[n];
        for(int i=0;i<n;++i) 
            a[i] = pos[nextInt()];
        int len = 0;
        int[] last = new int[n+1];
        for(int i=0;i<n;++i) {
            if(len == 0 || last[len-1] >= a[i]) {
                last[len++] = a[i];
            }
            else {
                int le = 0, ri = len - 1;
                while(le < ri) {
                    int mi = (le + ri) / 2;
                    if(last[mi] <= a[i]) ri = mi;
                    else le = mi + 1;
                }
                last[le] = a[i]; 
            }
        }
        System.out.println(len);
    }
    
    public static void main(String[] args) {
        new BaiD().run();
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