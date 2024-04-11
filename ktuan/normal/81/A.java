import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    public void run() {
        char[] a = nextStr().toCharArray();
        char[] s = new char[a.length];
        int ns = 0;
        for(int i=0;i<a.length;++i) {
            s[ns++] = a[i];
            while(ns >= 2 && s[ns-1] == s[ns-2]) ns -= 2;
        }
        String output = new String(s, 0, ns);
        System.out.println(output);
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