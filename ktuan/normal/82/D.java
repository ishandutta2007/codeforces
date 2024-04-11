import java.io.*;
import java.util.*;
import java.math.*;

public class BaiD implements Runnable {
    
    int n;
    int[] a;
    int[][] F;
    
    int solve(int i, int j) {
        if(i == n + 1) {
            return 0;
        }
        else if(i == n) {
            return a[j];
        }
        int ret = F[i][j];
        if(ret != -1) return ret;
        ret = 1000000010;
        ret = Math.min( ret, solve(i + 2, i + 1) + Math.max(a[i], a[j]));
        if(i + 1 < n)
            ret = Math.min( ret, solve( i + 2, i) + Math.max(a[j], a[i+1]));
        if(i + 1 < n)
            ret = Math.min( ret, solve(i + 2, j) + Math.max(a[i], a[i+1]));
        return F[i][j] = ret;
    }
    
    ArrayList<int[]> ar;
    
    void truy(int i, int j) {
        if(i == n+1) return;
        else if(i == n) {
            ar.add(new int[]{j});
        }
        else {
            int ret = solve(i,j);
            if(ret == solve(i+2, i+1) + Math.max(a[i], a[j])) {
                ar.add(new int[]{i,j});
                truy(i+2,i+1);
            }
            else if(i+1<n && ret == solve(i+2,i) + Math.max(a[j], a[i+1])) {
                ar.add(new int[]{j,i+1});
                truy(i+2,i);
            }
            else if(i+1<n && ret == solve(i + 2, j) + Math.max(a[i], a[i+1])) {
                ar.add(new int[]{i,i+1});
                truy(i+2,j);
            }
        }
    }
    
    public void run() {
        n = nextInt();
        a = new int[n];
        for(int i=0;i<n;++i)
            a[i] = nextInt();
        F = new int[n][n];
        for(int[] a1 : F)
            Arrays.fill(a1, -1);
        int res = solve( 1, 0);
        System.out.println(res);
        ar = new ArrayList<int[]>();
        truy( 1, 0);
        for(int[] z : ar) {
            for(int j=0;j<z.length;++j)
                System.out.print((z[j]+1) + " ");
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
        new BaiD().run();
    }
}