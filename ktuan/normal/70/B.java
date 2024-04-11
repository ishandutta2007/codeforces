import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
    
    public void run() {
        int n = nextInt();
        String line = null;
        try {
            line = keyboard.readLine();
        } catch(Exception ex) {
            
        }
        
        int[] a = new int[100000];
        int na = 0;
        
        int cur = 0;
        
        for(int i=0;i<line.length();++i) {
            char c = line.charAt(i);
            if(c == '.' || c == '?' || c == '!') {
                a[na++] = cur;
                cur = 0;
            }
            else ++cur;
        }
        
        a[0]++;
        
        cur = 0;
        int res = 0;
        for(int i=0;i<na;++i) {
            // System.out.println(a[i]);
            if(a[i] > n) {
                System.out.println("Impossible");
                return;
            }
            else {
                if(cur + (cur == 0 ? 0 : 1) + a[i] > n) {
                    cur = a[i];
                    ++res;
                }
                else {
                    cur = cur + (cur == 0 ? 0 : 1) + a[i];
                }
            }
        }
        if(cur > 0) ++res;
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