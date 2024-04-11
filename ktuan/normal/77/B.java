import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
    
    public void run() {
        int ntest = nextInt();
        for(int i=0;i<ntest;++i) {
            double a = nextDouble();
            double b = nextDouble();
            double x = Math.min(b, a / 4);
            double res;
            if(a == 0) {
                if(b == 0) res = 1;
                else res = 0.5;
            }
            else {
                if(b == 0) res = 1;
                else res = (x - 2 * x * x / a) / b / 2 + 0.5;
            }
            System.out.printf("%.8f\n", res);
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
        new BaiB().run();
    }
}