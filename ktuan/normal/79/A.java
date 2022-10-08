import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
    
    public void run() {
        int x = nextInt();
        int y = nextInt();
        int p = 0;
        while(true) {
            if(x >= 2 && y >= 2) {
                x -= 2; y -= 2;
            }
            else if(x >= 1 && y >= 12) {
                x -= 1; y -= 12;
            }
            else if(x >= 0 && y >= 22) {
                x -= 0; y -= 22;
            }
            else {
                System.out.println("Hanako");
                return;
            }
            if(x >= 0 && y >= 22) {
                x -= 0; y -= 22;
            }
            else if(x >= 1 && y >= 12) {
                x -= 1; y -= 12;
            }
            else if(x >= 2 && y >= 2) {
                x -= 2; y -= 2;
            } 
            else {
                System.out.println("Ciel");
                return;
            }
            
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