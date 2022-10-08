import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    public void run() {
        int n = nextInt();
        char[][] a = new char[4][n];
        if(n % 2 == 0) {
            for(int i=0;i<n;i+=2) {
                char c = 'a';
                if(i % 4 == 0) c = 'b'; 
                a[0][i] = a[0][i+1] = a[3][i] = a[3][i+1] = c;
            }
            for(int i=1;i+1<n;i+=2) {
                char c = 'w';
                if(i % 4 == 1) c = 'x'; 
                a[1][i] = a[1][i+1] = c;
                a[2][i] = a[2][i+1] = (char)(c + 2);
            }
            a[1][0] = a[2][0] = 'u';
            a[1][n-1] = a[2][n-1] = 'v';
        }
        else {
            for(int i=0;i+1<n;i+=2) {
                char c = 'a';
                if(i % 4 == 0) c = 'b'; 
                a[0][i] = a[0][i+1] = c;
                a[1][i] = a[1][i+1] = (char)(c + 2);
            }
            for(int i=1;i+1<n;i+=2) {
                char c = 'p';
                if(i % 4 == 1) c = 'q'; 
                a[2][i] = a[2][i+1] = c;
                a[3][i] = a[3][i+1] = (char)(c + 2);
            }
            a[0][n-1] = a[1][n-1] = 'x';
            a[2][0] = a[3][0] = 'y';
        }
        for(int i=0;i<4;++i) {
            for(int j=0;j<n;++j) System.out.print(a[i][j]);
            System.out.println();
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